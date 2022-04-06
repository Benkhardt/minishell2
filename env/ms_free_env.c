
#include "../minishell_libs.h"

void	free_env(t_struct *st)
{
	int	i;

	i = 0;
	while (st->env[i])
	{
		free(st->env[i]);
		i++;
	}
	free(st->env);
	free(st->prompt);
	exit(g_exit_value);
}
