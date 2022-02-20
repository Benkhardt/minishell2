/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_manage_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:14:36 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/08 09:27:05 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	ms_run_env(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	if (arr->cmd[1])
	{
		write(2, "env: Unexpected argument\n", 26);
		return (127);
	}
	ms_env(st);
	return (0);
}

int	ms_run_export(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;
	int			n;

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	n = 1;
	if (st->nb_cmd > 1)
		return (0);
	while (arr->cmd[n])
	{
		if (ft_strchr(arr->cmd[n], '='))
		{
			if (ms_export(arr->cmd[n], st) != 0)
				return (1);
		}
		n++;
	}
	return (0);
}

int	ms_run_unset(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;
	int			n;

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	n = 1;
	while (arr->cmd[n])
	{
		if (ms_unset(arr->cmd[n], st) != 0)
			return (1);
		n++;
	}
	return (0);
}
