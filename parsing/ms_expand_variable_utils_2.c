#include "../minishell_libs.h"

int	do_not_expand_variable(t_struct *st, char *str, int i)
{
	if (str[i + 1 == '"' || str[i + 1] == '\''])
		st->buf = add_char_to_buf(st, str[i]);
	st->buf = add_char_to_buf(st, str[i + 1]);
	return (i + 1);
}
