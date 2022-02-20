/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_launch_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 11:26:13 by flormich          #+#    #+#             */
/*   Updated: 2021/12/15 11:32:13 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_libs.h"

static void	exec_child(t_struct *st, int tr, int *next_fd)
{
	if (st->arr[tr].limiter != NULL)
		read_till_limiter(st, tr);
	set_red_shell(st, st->tr, next_fd);
	if (st->arr[tr].fd_out != 1)
		dup2(st->arr[tr].fd_out, STDOUT_FILENO);
	execve(st->arr[tr].cmd[0], st->arr[tr].cmd, NULL);
}

static void	manage_fd(t_struct *st, int *next_fd)
{
	if (st->tr < st->nb_cmd)
		dup2(next_fd[READ], st->fd[READ]);
	close(next_fd[READ]);
	close(next_fd[WRITE]);
	close(st->fd[WRITE]);
}

static int	launch_pipe(t_struct*st)
{
	pid_t	pid;
	int		status;
	int		next_fd[2];

	if (pipe(next_fd) == -1)
		return (-1);
	status = 0;
	pid = fork();
	if (pid < 0)
		perror ("Failed to create Child");
	if (pid == 0)
		exec_child(st, st->tr, next_fd);
	manage_fd(st, next_fd);
	if (waitpid(pid, &status, 0) < 0)
		return (-1);
	if (WIFEXITED(status))
		g_exit_value = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_exit_value = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGQUIT)
			ft_putendl_fd("Quit (core dumped)", 2);
	}
	return (0);
}

int	launch_cmd(t_struct *st)
{
	if (pipe(st->fd) == -1)
		return (-1);
	while (st->tr < st->nb_cmd)
	{
		if (st->arr[st->tr].cmd_type == BUILTIN)
			launch_builtin(st);
		else
		{
			if (launch_pipe(st) == -1)
				return (-1);
		}
		st->tr++;
	}
	return (0);
}
