/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_set_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 11:52:27 by flormich          #+#    #+#             */
/*   Updated: 2021/12/14 09:12:27 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_libs.h"

// STDIN = 0, STDOUT = 1, STDERR = 2
void	set_red_shell(t_struct *st, int which_cmd, int *next_fd)
{
	if (st->nb_cmd == 1)
	{
		dup2(st->arr[which_cmd].fd_in, STDIN_FILENO);
		dup2(st->arr[which_cmd].fd_out, STDOUT_FILENO);
	}
	else if (which_cmd == 0)
	{
		dup2(st->arr[which_cmd].fd_in, STDIN_FILENO);
		if (st->arr[which_cmd].fd_out != 1)
			dup2(st->arr[which_cmd].fd_out, STDOUT_FILENO);
		else
			dup2(next_fd[WRITE], STDOUT_FILENO);
	}
	else
	{
		dup2(st->fd[READ], STDIN_FILENO);
		if (which_cmd == st->nb_cmd - 1)
			dup2(st->arr[which_cmd].fd_out, STDOUT_FILENO);
		else
			dup2(next_fd[WRITE], STDOUT_FILENO);
	}
	close(st->fd[READ]);
	close(st->fd[WRITE]);
}

int	launch_builtin(t_struct *st)
{
	if (st->arr[st->tr].f_ptr == &run_echo
		&& st->tr + 1 != st->nb_cmd && st->arr[st->tr + 1].f_ptr == &run_echo)
		return (0);
	if (st->tr + 1 == st->nb_cmd)
		dup2(st->arr[st->tr].fd_out, st->fd[WRITE]);
	g_exit_value = st->arr[st->tr].f_ptr(st, &(st->arr[st->tr]));
	return (0);
}
