#include"../minishell_libs.h"

// How to put § : error: multi-character character constant [-Werror=multichar]
int	is_variable_end(t_struct *st, unsigned char c)
{
	if (c == ' ' || c == '"' || c == '\'' || c == '*' || c == '#'
		|| c == '%' || c == '\\' || c == '$' || c == '{' || c == '}'
		|| c == '\0' || c == '\n')
		return (1);
	else if (c == '!' || c == '&' || c == '/' || c == '='
		|| c == '?' || c == '-' || c == '@' || c == '|' || c == '~')
		return (1);
	else if (c == '>' || c == '<' )
	{
		st->cancel = 1;
		perror("-bash: syntax error near unexpected token 'newline'\n");
	}
	return (0);
}

int	is_special_variable(unsigned char c)
{
	if (c == '$' || c == '?' || c == '@' || c == '*' || c == '{'
		|| c == '"' || c == '#' || c == '~')
		return (1);
	return (0);
}

int	is_expand_home(unsigned char c)
{
	if (c == ' ' || c == '\0' || c == '\n')
		return (1);
	return (0);
}
