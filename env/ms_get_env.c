/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnuti <pnuti@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:39:27 by pnuti             #+#    #+#             */
/*   Updated: 2021/11/24 14:24:02 by pnuti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

char	*ms_get_env(char **env, char *varname)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], varname, ft_len_until_char(env[i], '=')))
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}
