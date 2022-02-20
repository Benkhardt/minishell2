/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:55:53 by flormich          #+#    #+#             */
/*   Updated: 2021/12/11 18:54:46 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_libs.h"

int	ms_error(char *txt, int exit_level, t_struct *st)
{
	perror(txt);
	st->tr = st->tr;
	if (exit_level == 0)
		return (-1);
	return (0);
}

void	ms_error_synthaxe(char c)
{
	if (c == '\0' || c == '\n')
		printf("-bash: syntax error near unexpected token `newline'\n");
	else if (c == '|')
		printf("-bash: syntax error near unexpected token `|'\n");
	else if (c == '>')
		printf("-bash: syntax error near unexpected token `>'\n");
	else if (c == '<')
		printf("-bash: syntax error near unexpected token `<'\n");
	else if (c == '}')
		printf("-bash: ${}: bad substitution\n");
	else if (c == 't')
		printf("-bash: cd: too many arguments\n");
	else if (c == '?')
		printf("-bash: |: missing command\n");
	else if (c == 'C')
		printf("-bash: command not found\n");
	else if (c == '"' || c == '\'')
		printf("-bash: unclosed quote\n");
	else
		printf("-bash: syntax error near unexpected token '%c'\n", c);
}
