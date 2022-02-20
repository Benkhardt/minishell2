/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_extract_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:58:31 by flormich          #+#    #+#             */
/*   Updated: 2021/12/03 21:34:42 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell_libs.h"

// Malloc memory for file names
char	*malloc_f_name(char **file, int len)
{
	if (*file)
		free(*file);
	return (ft_calloc(len + 1, sizeof(char)));
}

// Test if file descriptor OK
int	test_fd(int fd, char *name)
{
	if (fd == -1)
	{
		printf("-bash: %s: No such file or directory\n", name);
		return (-1);
	}
	return (0);
}

// Open outputfile
int	open_outfile(char *name, int append)
{
	if (append == 1)
		return (open(name, O_RDWR | O_CREAT | O_APPEND, 0777));
	else if (append == 0)
		return (open(name, O_RDWR | O_CREAT | O_TRUNC, 0777));
	else
		return (-1);
}

// Skipp the portion in-between "" or ''
// (used by count_arg)
int	skip_double_quote(char *input, int i, int max)
{
	while (i <= max
		&& (input[i] != '"' || (input[i] == '"' && input[i - 1] == '\\')))
	{
		if (i == max || input[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int	skip_simple_quote(char *input, int i, int max)
{
	while (i <= max && input[i] != '\'')
	{
		if (i == max || input[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}
