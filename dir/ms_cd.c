/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:50:14 by pnuti             #+#    #+#             */
/*   Updated: 2021/12/15 11:20:01 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

static int	update_prompt(t_struct *st, char *pfad)
{
	char	*tmp;
	char	*home;
	char	*tmp2;
	int		len;

	tmp = st->prompt;
	tmp2 = pfad;
	home = ms_get_env(st->env, "HOME");
	len = ft_strlen(home);
	if (home)
	{
		if (ft_strncmp(pfad, home, len) == 0)
			tmp2 = ft_strjoin("\033[0;32m~", pfad + len);
	}
	st->prompt = ft_strjoin(tmp2, "$ \033[0m");
	if (tmp2 != pfad)
		free(tmp2);
	free(tmp);
	return (0);
}

static int	update_vars(t_struct *st)
{
	char	*old_wd;
	char	*current_wd;
	char	cwd[PATH_MAX];

	old_wd = ft_strjoin("OLDPWD=", ms_get_env(st->env, "PWD"));
	if (!old_wd)
		return (1);
	if (ms_export(old_wd, st) != 0)
		return (1);
	free(old_wd);
	if (!getcwd(cwd, PATH_MAX))
		return (1);
	current_wd = ft_strjoin("PWD=", cwd);
	if (!current_wd)
		return (1);
	if (ms_export(current_wd, st) != 0)
		return (1);
	update_prompt(st, ft_strchr(current_wd, '/'));
	free(current_wd);
	return (0);
}

static int	dash_syntax(t_struct *st, t_cmd *arr)
{
	char		*old_tmp;

	old_tmp = ms_get_env(st->env, "OLDPWD");
	if (!old_tmp)
	{
		write(2, "minishell: cd: OLDPWD not set\n", 31);
		return (1);
	}
	free(arr->cmd[1]);
	arr->cmd[1] = ft_strdup(old_tmp);
	return (0);
}

static int	implement_syntax(t_struct *st, t_cmd *arr)
{
	if (!arr->cmd[1])
		return (chdir(ms_get_env(st->env, "HOME")) * -1);
	else if (arr->cmd[1][0] == '-' && ft_strlen(arr->cmd[1]) == 1)
	{
		if (dash_syntax(st, arr))
			return (1);
	}
	if (chdir(arr->cmd[1]) < 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

int	cd(void *stt, void *cmd)
{
	t_cmd		*arr;
	t_struct	*st;

	arr = (t_cmd *)cmd;
	st = (t_struct *)stt;
	if (st->nb_cmd != 1)
		return (-1);
	if (arr->cmd[1] && arr->cmd[2] != NULL)
	{
		st->nb_cmd = 0;
		return (1);
	}
	else if (implement_syntax(st, arr))
		return (1);
	update_vars(st);
	return (0);
}
