/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_variable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:01:48 by flormich          #+#    #+#             */
/*   Updated: 2021/12/14 09:12:52 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

int	count_pipe_skip_space(t_struct *st, char *str, int i)
{
	if (str[i] == '|')
	{
		st->nb_cmd += 1;
		if (str[i - 1] != ' ')
			st->buf = add_char_to_buf(st, ' ');
	}
	st->buf = add_char_to_buf(st, str[i]);
	while (ft_isspace(str[i]) == 1 && str[i + 1] != '\0'
		&& ft_isspace(str[i + 1]) == 1)
		i++;
	return (i);
}

static int	go_to_variable_end(t_struct *st, char *str, int i)
{
	while (is_variable_end(st, str[i]) == 0)
		i++;
	while (str[i] == '#')
		st->buf = add_char_to_buf(st, str[i++]);
	return (i);
}

int	expand_variable(t_struct *st, char *str, int i)
{
	int		e;
	int		new_pos;
	char	*tmp_ptr;

	if (str[i] == '~')
	{
		tmp_ptr = st->buf;
		st->buf = ft_strjoin(st->buf, ms_get_env(st->env, "HOME"));
		free(tmp_ptr);
		return (i);
	}
	else
	{
		e = 0;
		while (st->env[e])
		{
			new_pos = find_match(st, e, str, i + 1);
			if (new_pos != 0)
				return (new_pos);
			e++;
		}
		i++;
		i = go_to_variable_end(st, str, i);
	}
	return (i - 1);
}

static int	expand_bracket(t_struct *st, char *str, int i)
{
	if (str[i + 1] == '}')
	{
		st->cancel = 1;
		ms_error_synthaxe('}');
		return (-3);
	}
	return (expand_variable(st, str, i));
}

//@ && * make nothing
int	expand_special_variable(t_struct *st, char *str, int i)
{
	if (str[i + 1] == '$')
		st->buf = add_number_to_buf(st, getpid());
	else if (str[i + 1] == '?')
		st->buf = add_number_to_buf(st, g_exit_value);
	else if (str[i + 1] == '#')
		st->buf = add_number_to_buf(st, st->res_dash);
	else if (str[i + 1] == '~')
	{
		st->buf = add_char_to_buf(st, '$');
		st->buf = add_char_to_buf(st, '~');
	}
	else if (str[i + 1] == '"')
	{
		st->buf = add_char_to_buf(st, '$');
		return (i);
	}
	else if (str[i + 1] == '{')
		i = expand_bracket(st, str, i + 1);
	return (i + 1);
}
