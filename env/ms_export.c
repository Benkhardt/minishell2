/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 17:23:00 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/08 09:18:41 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

static int	env_exists(char *new_var, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(new_var, env[i], ft_len_until_char(new_var, '='))
			&& !ft_strncmp(new_var, env[i], ft_len_until_char(env[i], '=')))
			return (1);
		i++;
	}
	return (0);
}

static void	sub_or_append(char *newvar, t_struct *st, char **new_env)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (st->env[i])
	{
		if (!ft_strncmp(newvar, st->env[i], ft_len_until_char(st->env[i], '='))
			&& !ft_strncmp(newvar, st->env[i], ft_len_until_char(newvar, '=')))
		{
			free(st->env[i]);
			new_env[i] = ft_strdup(newvar);
			check += 1;
		}
		else
			new_env[i] = st->env[i];
		i++;
	}
	if (!check)
	{
		new_env[i] = ft_strdup(newvar);
		i++;
	}
	new_env[i] = NULL;
}

int	ms_export(char *new_var, t_struct *st)
{
	char	**env;
	int		n;

	n = ft_2darr_len(st->env);
	if (!env_exists(new_var, st->env))
		n++;
	env = (char **)malloc(sizeof(char *) * (n + 1));
	if (!env)
		return (1);
	sub_or_append(new_var, st, env);
	free(st->env);
	st->env = env;
	return (0);
}
