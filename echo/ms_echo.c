/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:30:48 by flormich          #+#    #+#             */
/*   Updated: 2021/12/12 09:56:56 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	initialise_buf(t_struct *st)
{
	st->cancel = 0;
	st->buf = ft_calloc(1, sizeof(char *));
	if (!st->buf)
		return (-1);
	return (0);
}

static int	test_flag_n(t_cmd *arr)
{
	int	i;
	int	j;

	i = 1;
	while (arr->cmd[i])
	{
		j = 2;
		if (ft_strncmp(arr->cmd[i], "-n", 2) == 0)
		{
			while (arr->cmd[i][j] == 'n' && arr->cmd[i][j] != '\0')
				j++;
			if (arr->cmd[i][j] == '\0')
				i++;
			else
				return (i);
		}
		else
			return (i);
	}
	return (i);
}

int	is_writable_x(t_struct *st, char c, char c_next)
{
	if (c == '\\'
		|| (c == '$' && c_next == '"'))
		return (0);
	if (c == '(' || c == ')' )
	{
		st->cancel = 1;
		ms_error_synthaxe(c);
		return (0);
	}
	if (c == '>' || c == '<' )
	{
		st->cancel = 1;
		ms_error_synthaxe('\n');
		return (0);
	}
	return (1);
}

void	bufferize_cmd(t_struct *st, t_cmd *arr, int arg, int i)
{
	while (arr->cmd[arg][i] != '\0' && st->cancel == 0)
	{
		if (arr->cmd[arg][i] == '"')
			i = echo_double_quote(st, arr, arg, i + 1);
		else if (arr->cmd[arg][i] == '\'')
			i = echo_simple_quote(st, arr, arg, i + 1);
		else if (arr->cmd[arg][i] == '\\')
		{
			i++;
			if (arr->cmd[arg][i] != '\0')
				st->buf = add_char_to_buf(st, arr->cmd[arg][i]);
			else
				i--;
		}
		else if (is_writable_x(st, arr->cmd[arg][i], arr->cmd[arg][i + 1]) == 1)
			st->buf = add_char_to_buf(st, arr->cmd[arg][i]);
		i++;
	}
	st->buf = add_char_to_buf(st, ' ');
}

// if pos_arg > 1: there is a valid -n flag
int	run_echo(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;
	int			pos_arg;
	int			arg;

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	if (st->tr + 1 == st->nb_cmd)
	{
		if (initialise_buf(st) == 0)
		{
			pos_arg = test_flag_n(arr);
			arg = pos_arg;
			while (arr->cmd[arg] && st->cancel == 0)
				bufferize_cmd(st, arr, arg++, 0);
			if (st->cancel == 0)
			{
				ft_putstr_fd(st->buf, st->fd[WRITE]);
				if (pos_arg == 1)
					write(st->fd[WRITE], "\n", 1);
			}
			free(st->buf);
		}
	}
	return (0);
}
