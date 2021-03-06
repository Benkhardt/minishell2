#include"../minishell_libs.h"

int	parse_space(t_struct *st, int i)
{
	if (st->digit != 0)
	{
		st->arg++;
		st->digit = 0;
	}
	return (i + 1);
}

int	parse_pipe(t_struct *st, int i)
{
	st->tr++;
	st->arg = 0;
	st->digit = 0;
	return (i + 1);
}

int	parse_redirection(t_struct *st, int i)
{
	st->arg = 0;
	st->digit = 0;
	i = extract_redirection(st, i);
	if (i == -1)
		return (-1);
	return (i);
}

int	parse_char(t_struct *st, char *input, int i)
{
	st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
	st->digit++;
	i++;
	if (input[i] == '"' || input[i] == '\'')
	{
		st->arr[st->tr].cmd[st->arg][st->digit] = input[i];
		st->digit++;
		i++;
	}
	return (i);
}
