/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_variable_utils_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:31:57 by flormich          #+#    #+#             */
/*   Updated: 2021/12/12 10:03:03 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	do_not_expand_variable(t_struct *st, char *str, int i)
{
	if (str[i + 1 == '"' || str[i + 1] == '\''])
		st->buf = add_char_to_buf(st, str[i]);
	st->buf = add_char_to_buf(st, str[i + 1]);
	return (i + 1);
}
