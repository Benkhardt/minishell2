/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_2_parse_input_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:21:12 by flormich          #+#    #+#             */
/*   Updated: 2021/12/02 09:42:16 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell_libs.h"

int	parse_quote(t_struct *st, char *input, int i)
{
	if (input[i] == '\'')
		return (parse_simple_quote(st, input, i));
	return (parse_double_quote(st, input, i));
}

int	parse_double_quote(t_struct *st, char *input, int i)
{
	st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
	st->digit++;
	i++;
	while (input[i] != '"' || (input[i] == '"' && input[i - 1] == '\\'))
	{
		st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
		st->digit++;
		i++;
	}
	st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
	st->digit++;
	return (i + 1);
}

int	parse_simple_quote(t_struct *st, char *input, int i)
{
	st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
	st->digit++;
	i++;
	while (input[i] != '\'' && input[i] != '\0')
	{
		st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
		st->digit++;
		i++;
	}
	st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
	st->digit++;
	return (i + 1);
}
