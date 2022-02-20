/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:57:27 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/05 22:10:19 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

static void	find_and_del(char *varname, char **old_env, char **new_env)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (old_env[i + check])
	{
		if (!ft_strncmp(varname, old_env[i], ft_len_until_char(old_env[i], '='))
			&& !ft_strncmp(varname, old_env[i], ft_strlen(varname)) && !check)
		{
			free(old_env[i]);
			old_env[i] = NULL;
			if (old_env[i + 1] != NULL)
				check += 1;
		}
		if (old_env[i + check])
		{
			new_env[i] = old_env[i + check];
			i++;
		}
	}
	new_env[i] = NULL;
}

int	ms_unset(char *var_name, t_struct *st)
{
	char	**env;
	int		n;

	if (st->nb_cmd != 1)
		return (-1);
	if (!ms_get_env(st->env, var_name))
		return (0);
	n = ft_2darr_len(st->env);
	env = (char **)malloc(sizeof(char *) * n);
	if (!env)
		return (1);
	find_and_del(var_name, st->env, env);
	free(st->env);
	st->env = env;
	return (0);
}
