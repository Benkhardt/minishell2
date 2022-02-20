/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:28:43 by flormich          #+#    #+#             */
/*   Updated: 2021/12/15 12:34:58 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	create_tmp(t_struct *st, int tr)
{
	st->arr[tr].name_in = ft_strdup("tmp_limite");
	st->arr[tr].fd_in = open(st->arr[tr].name_in, O_CREAT | O_RDWR, 0777);
	if (test_fd(st->arr[st->tr].fd_in, "tmp_limite") == -1)
		return (-1);
	return (0);
}

int	extract_limiter(t_struct *s, int i)
{
	int		len;
	int		j;

	i = test_synthaxe(s, i, LIMITER);
	if (i == -1)
		return (-1);
	len = count_lengh_name(s, i, 1);
	if (len == 0)
		return (-1);
	s->arr[s->tr].limiter = malloc_f_name(&(s->arr[s->tr].limiter), len + 1);
	if (!s->arr[s->tr].limiter)
		ms_error("Failed to malloc limiter\n", 0, s);
	j = 0;
	while (j < len)
		s->arr[s->tr].limiter[j++] = s->input[i++];
	s->arr[s->tr].limiter[j] = '\0';
	if (create_tmp(s, s->tr) == -1)
		return (-1);
	return (i);
}

// Find input file name and test if valid
int	extract_infile(t_struct *s, int i)
{
	int	len;
	int	j;

	i = test_synthaxe(s, i, INFILE);
	if (i == -1)
		return (-1);
	len = count_lengh_name(s, i, 1);
	if (len == 0)
		return (-1);
	s->arr[s->tr].name_in = malloc_f_name(&(s->arr[s->tr].name_in), len + 1);
	if (!s->arr[s->tr].name_in)
		ms_error("Failed to malloc infile\n", 0, s);
	j = 0;
	while (j < len)
		s->arr[s->tr].name_in[j++] = s->input[i++];
	s->arr[s->tr].name_in[j] = '\0';
	s->arr[s->tr].fd_in = open(s->arr[s->tr].name_in, O_RDWR, 0777);
	if (test_fd(s->arr[s->tr].fd_in, s->arr[s->tr].name_in) == -1)
		return (-1);
	return (i);
}

// Find output file name and test if valid and put it in the cmd struct
int	extract_outfile(t_struct *s, int i)
{
	int	len;
	int	j;
	int	append;

	append = 0;
	if (s->input[i] == '>')
		append = 1;
	i = test_synthaxe(s, i, OUTFILE);
	if (i == -1)
		return (-1);
	len = count_lengh_name(s, i, 1);
	if (len == 0)
		return (-1);
	s->arr[s->tr].name_out = malloc_f_name(&(s->arr[s->tr].name_out), len + 1);
	if (!s->arr[s->tr].name_out)
		ms_error("Failed to malloc infile\n", 0, s);
	j = 0;
	while (j < len)
		s->arr[s->tr].name_out[j++] = s->input[i++];
	s->arr[s->tr].name_out[j] = '\0';
	s->arr[s->tr].fd_out = open_outfile(s->arr[s->tr].name_out, append);
	if (test_fd(s->arr[s->tr].fd_out, s->arr[s->tr].name_out) == -1)
		return (-1);
	return (i);
}
