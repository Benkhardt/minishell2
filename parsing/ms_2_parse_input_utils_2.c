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
