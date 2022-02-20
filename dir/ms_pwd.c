/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:24:11 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/07 15:24:31 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	pwd(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;
	char		buf[PATH_MAX];

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	arr->cmd[1] = arr->cmd[1];
	st->arr[0].cmd[1] = st->arr[0].cmd[1];
	if (!getcwd(buf, PATH_MAX))
	{
		perror("Current directory unknown");
		return (-1);
	}
	ft_putendl_fd(buf, st->fd[WRITE]);
	return (0);
}
