/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:23:50 by flormich          #+#    #+#             */
/*   Updated: 2021/12/02 12:32:17 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

static int	print_alone(char c)
{
	if (c == '"' || c == '$')
		return (1);
	return (0);
}

int	echo_double_quote(t_struct *st, t_cmd *arr, int arg, int i)
{
	while (arr->cmd[arg][i] != '"' && arr->cmd[arg][i] != '\0')
	{
		if (arr->cmd[arg][i] == '\\' && print_alone(arr->cmd[arg][i + 1]) == 1)
		{
			i++;
		}
		st->buf = add_char_to_buf(st, arr->cmd[arg][i++]);
	}
	return (i);
}

int	echo_simple_quote(t_struct *st, t_cmd *arr, int arg, int i)
{
	while (arr->cmd[arg][i] != '\'' && arr->cmd[arg][i] != '\0')
		st->buf = add_char_to_buf(st, arr->cmd[arg][i++]);
	return (i);
}
