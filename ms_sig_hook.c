/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sig_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbenkhar <dbenkhar@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:48:42 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/17 15:06:32 by dbenkhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_libs.h"

void	sigint_handle(int signum)
{
	static int	check;

	if (signum == SIGUSR1)
	{
		if (!check)
			check = 1;
		else
			check = 0;
	}
	if (signum == SIGINT)
	{
		g_exit_value = 130;
		printf("\n");
		//rl_replace_line("", 0);
		rl_on_new_line();
		if (!check)
			rl_redisplay();
	}
}

void	sig_handle(int signum)
{
	if (signum == SIGINT)
		sigint_handle(signum);
	else if (signum == SIGQUIT)
		printf("\b\b  \b\b");
}

int	ms_sig_hook(void)
{
	struct sigaction	sa;

	sa.sa_handler = &sig_handle;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (-1);
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		return (-2);
	return (0);
}
