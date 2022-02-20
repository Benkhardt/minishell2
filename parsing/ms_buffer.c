/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:42:51 by flormich          #+#    #+#             */
/*   Updated: 2021/12/12 10:08:41 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

static char	*calloc_buf(char *alt_buf, int size)
{
	char	*new_buf;

	new_buf = ft_calloc(ft_strlen(alt_buf) + size, sizeof(char));
	if (!new_buf)
		perror("Failed to malloc new_buffer\n");
	return (new_buf);
}

char	*add_char_to_buf(t_struct *st, char c)
{
	int		j;
	char	*new_buf;

	new_buf = calloc_buf(st->buf, 2);
	if (!new_buf)
		return (NULL);
	j = 0;
	while (st->buf[j] != '\0')
	{
		new_buf[j] = st->buf[j];
		j++;
	}
	new_buf[j++] = c;
	new_buf[j] = '\0';
	free(st->buf);
	return (new_buf);
}

char	*add_number_to_buf(t_struct *st, int nb)
{
	char	*str;
	int		i;
	int		j;
	char	*new_buf;

	str = ft_itoa(nb);
	new_buf = calloc_buf(st->buf, ft_strlen(str) + 1);
	i = 0;
	while (st->buf[i] != '\0')
	{
		new_buf[i] = st->buf[i];
		i++;
	}
	j = 0;
	while (str[j] != '\0')
	{
		new_buf[i + j] = str[j];
		j++;
	}
	free(str);
	free(st->buf);
	return (new_buf);
}

int	transfert_buf_input(t_struct *st)
{
	char	*tmp;

	st->len = ft_strlen(st->buf);
	if (st->buf[st->len - 1] == '|'
		|| (st->buf[st->len - 1] == ' ' && st->buf[st->len - 2] == '|'))
	{
		ms_error_synthaxe('?');
		free(st->buf);
		free(st->input);
		return (-1);
	}
	tmp = st->input;
	st->input = ft_strdup(st->buf);
	free(tmp);
	free(st->buf);
	if (st->input && st->input[0] != '\0')
		return (0);
	return (-1);
}
