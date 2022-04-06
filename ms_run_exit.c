#include "minishell_libs.h"

static int	is_all_num(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	run_exit(void *stt, void *cmd)
{
	t_struct	*st;
	t_cmd		*arr;

	st = (t_struct *)stt;
	arr = (t_cmd *)cmd;
	if (st->nb_cmd != 1)
		return (-1);
	if (!arr->cmd[1])
		g_exit_value = 0;
	else
	{
		g_exit_value = ft_atoi(arr->cmd[1]);
		if (!is_all_num(arr->cmd[1]))
		{
			g_exit_value = 2;
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		}
	}
	free_memory(st);
	free_env(st);
	return (0);
}
