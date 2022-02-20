/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parse_st.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:34:59 by flormich          #+#    #+#             */
/*   Updated: 2021/10/21 19:49:50 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell_libs.h"

// create the maximum size ***arr according to the number of pipes
static t_cmd	*create_arr(t_struct *st)
{
	t_cmd	*arr;

	arr = malloc(st->nb_cmd * sizeof(t_cmd));
	if (!arr)
		ms_error("Fail to malloc arr_st_arg in ***parse_st", 0, st);
	return (arr);
}

// Pilote the parsing of the input string
int	extract_cmd(t_struct *st)
{
	int	sucess;

	sucess = 0;
	st->arr = create_arr(st);
	if (!st->arr)
		(sucess = -1);
	else
	{
		if (parse_input(st) == -1)
			sucess = -1;
		else if (add_path(st) == -1)
			sucess = -2;
	}
	st->tr = 0;
	if (sucess < 0)
	{
		if (sucess == -1)
			g_exit_value = 2;
		return (-1);
	}
	return (0);
}
