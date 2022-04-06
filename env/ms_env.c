
#include "../minishell_libs.h"

void	ms_env(t_struct *st)
{
	int	i;

	i = 0;
	while (st->env[i])
	{
		ft_putendl_fd(st->env[i], st->fd[WRITE]);
		i++;
	}
}
