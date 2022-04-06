
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
