/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_clean_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:45:01 by flormich          #+#    #+#             */
/*   Updated: 2021/12/15 13:39:18 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell_libs.h"

static void	trim_quote(t_cmd *arr, char c, int arg)
{
	char	*tmp;

	if (c == '"')
		tmp = ft_strtrim(arr->cmd[arg], "\"");
	else
		tmp = ft_strtrim(arr->cmd[arg], "'");
	if (tmp)
	{
		free(arr->cmd[arg]);
		arr->cmd[arg] = tmp;
	}
}

static void	implement_cmd_typ(t_cmd *arr)
{
	if (ft_strncmp(arr->cmd[0], "echo", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &run_echo;
	else if (ft_strncmp(arr->cmd[0], "env", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &ms_run_env;
	else if (ft_strncmp(arr->cmd[0], "export", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &ms_run_export;
	else if (ft_strncmp(arr->cmd[0], "unset", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &ms_run_unset;
	else if (ft_strncmp(arr->cmd[0], "pwd", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &pwd;
	else if (ft_strncmp(arr->cmd[0], "cd", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &cd;
	else if (ft_strncmp(arr->cmd[0], "exit", ft_strlen(arr->cmd[0])) == 0)
		arr->f_ptr = &run_exit;
	else
	{
		arr->cmd_type = SHELL;
		return ;
	}
	arr->cmd_type = BUILTIN;
}

static int	launch_implement_cmd_typ(t_cmd *arr)
{
	int	i;

	if (arr->cmd[0][0] == '"' || arr->cmd[0][0] == '\'')
		trim_quote(arr, arr->cmd[0][0], 0);
	if (arr->cmd[0][0] != '\0')
	{
		implement_cmd_typ(arr);
		if (arr->f_ptr != &run_echo)
		{
			i = 1;
			while (arr->cmd[i][0] != '\0')
			{
				if (arr->cmd[i][0] == '"' || arr->cmd[i][0] == '\'')
					trim_quote(arr, arr->cmd[i][0], i);
				i++;
			}
		}
	}
	if (arr->cmd[0][0] != '\0')
		return (0);
	return (-1);
}

int	clean_arr(t_struct *st)
{
	st->tr = 0;
	while (st->tr < st->nb_cmd)
	{
		st->arg = 0;
		if (launch_implement_cmd_typ(&(st->arr[st->tr])) == 0)
		{
			while (st->tr < st->nb_cmd && st->arg < st->arr[st->tr].nb_arg
				&& st->arr[st->tr].cmd[st->arg][0] != '\0')
				st->arg++;
			free(st->arr[st->tr].cmd[st->arg]);
			st->arr[st->tr].cmd[st->arg++] = (char *)0;
			st->digit = 0;
			while (st->arg <= st->arr[st->tr].nb_arg)
			{
				free(st->arr[st->tr].cmd[st->arg]);
				st->digit++;
				st->arg++;
			}
			st->arr[st->tr].nb_arg -= st->digit;
		}
		else if (st->tr == 0)
			return (-1);
		st->tr++;
	}
	return (0);
}
