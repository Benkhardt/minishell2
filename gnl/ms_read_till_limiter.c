/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_read_till_limiter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:48:35 by flormich          #+#    #+#             */
/*   Updated: 2021/12/07 17:58:55 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	read_till_limiter(t_struct *st, int tr)
{
	int		i;

	i = 1;
	st->buf_tmp = (char *)gnl_calloc(1, 1);
	while (i > 0)
	{
		i = get_next_line(0, &st->buf_tmp, st->arr[tr].limiter, 0);
	}
	initialise_buf(st);
	bufferize_input(st, st->buf_tmp, 0, 0);
	i = ft_strlen(st->buf);
	if (st->tr + 1 == st->nb_cmd)
		dup2(st->arr[st->tr].fd_out, st->fd[WRITE]);
	write(st->fd[WRITE], st->buf, i);
	free(st->buf);
	free(st->buf_tmp);
	return (0);
}
