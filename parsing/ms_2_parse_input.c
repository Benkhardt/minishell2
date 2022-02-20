/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_2_parse_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:09:00 by flormich          #+#    #+#             */
/*   Updated: 2021/12/13 20:12:43 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell_libs.h"

static int	malloc_cmd(t_struct *st)
{
	int	tr;
	int	arg;

	tr = 0;
	while (tr < st->nb_cmd)
	{
		arg = 0;
		while (arg <= st->arr[tr].nb_arg)
		{
			st->arr[tr].cmd[arg] = ft_calloc(st->len + 1, sizeof(char));
			if (!st->arr[tr].cmd[arg])
				return (-1);
			arg++;
		}
		tr++;
	}
	return (tr);
}

// Screen the input string and save the command/opt/arg/redirection
// in the apropriate memory
static int	fill_cmd(char *input, t_struct *st, int i)
{
	while (i < st->len && i != -1)
	{
		if (ft_isspace(input[i]) == 1)
			i = parse_space(st, i);
		if (input[i] == '|' && st->all == 0)
			i = parse_pipe(st, i);
		if (st->all == 0 && (input[i] == '<' || input[i] == '>'))
			i = parse_redirection(st, i);
		if (i != -1 && (input[i] == '"' || input[i] == '\''))
			i = parse_quote(st, input, i);
		else if (i != -1 && i < st->len && ft_isspace(input[i]) == 0)
			i = parse_char(st, input, i);
	}
	return (i);
}

// Count for each command the number of option + argument in order to know
// whiche size to malloc
static int	count_arg(char *input, t_struct *st, int i)
{
	int		tr;

	tr = 0;
	while (i <= st->len && input[i] != '\0')
	{
		st->arr[tr].nb_arg = 0;
		while (input[i] != '|' && i <= st->len && input[i] != '\0')
		{
			if (input[i] == '"')
				i = skip_double_quote(input, i + 1, st->len);
			else if (input[i] == '\'')
				i = skip_simple_quote(input, i + 1, st->len);
			else if (ft_isspace(input[i]) == 1)
			{
				if (input[i + 1] != '|' && i < st->len)
					st->arr[tr].nb_arg++;
			}
			i++;
		}
		st->arr[tr].nb_arg++;
		tr++;
		i++;
	}
	return (tr);
}

static void	initialize_cmd(t_struct *st, int tr)
{
	st->arr[tr].fd_in = 0;
	st->arr[tr].fd_out = 1;
	st->arr[tr].name_in = NULL;
	st->arr[tr].name_out = NULL;
	st->arr[tr].limiter = NULL;
}

// Create the cmd array and lauch the parsing
int	parse_input(t_struct *st)
{
	int	tr;

	tr = 0;
	st->nb_cmd = count_arg(st->input, st, 0);
	if (st->nb_cmd == -1)
		return (-1);
	while (tr < st->nb_cmd)
	{
		st->arr[tr].cmd = malloc((st->arr[tr].nb_arg + 1) * sizeof(char *));
		if (!st->arr[tr].cmd)
			return (-1);
		initialize_cmd(st, tr);
		tr++;
	}
	if (malloc_cmd(st) == -1)
		return (-1);
	if (fill_cmd(st->input, st, 0) == -1)
		return (-1);
	if (clean_arr(st) == -1)
		return (-1);
	return (0);
}
