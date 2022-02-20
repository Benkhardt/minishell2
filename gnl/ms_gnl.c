/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:04:40 by flormich          #+#    #+#             */
/*   Updated: 2021/11/29 22:44:09 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

// Concatene s2 to s1 (s1=line)
char	*get_strjoin(char *s1, char *s2)
{
	char			*conc;
	unsigned int	len;
	int				i;
	int				j;

	len = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	conc = (char *)ft_calloc(len, sizeof(*s1));
	if (! conc)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		conc[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		conc[i + j] = s2[j];
		j++;
	}
	conc[i + j] = '\0';
	free(s1);
	free(s2);
	return (conc);
}

// Extract the new portion of the buffer and put it in line
int	get_extract_line(char **line, char *str, int stat_read)
{
	char	*new;
	int		pos_fin;
	int		full_line;

	if (stat_read == -1)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	if (gnl_strchr(str, '\n') != NULL)
		full_line = 1;
	else
		full_line = 0;
	pos_fin = get_lglen(str);
	new = gnl_substr((char const *)str, pos_fin + 1);
	if (*line == NULL || *line == 0)
		*line = new;
	else
		*line = get_strjoin(*line, new);
	if (pos_fin < BUFFER_SIZE - 1)
		gnl_memmove(str, str + pos_fin + 1, BUFFER_SIZE - pos_fin - 1);
	else
		gnl_bzero(str, BUFFER_SIZE);
	return (full_line);
}

// Manage the read till the next '\n' and return the line to the main
int	get_next_line(int fd, char **line, char *limiter, int stat_read)
{
	static char	buffer[BUFFER_SIZE] = {0};
	int			full_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
	{
		*line = 0;
		return (-1);
	}
	full_line = 0;
	while (full_line == 0)
	{
		if (buffer[0] == '\0')
		{
			gnl_bzero(buffer, BUFFER_SIZE);
			write(1, "> ", 2);
			stat_read = read(fd, buffer, BUFFER_SIZE);
			if (stat_read == 0)
				return (0);
			if (get_lglen(buffer) - 1 == ft_strlen(limiter)
				&& ft_strncmp(buffer, limiter, ft_strlen(limiter)) == 0)
				return (-1);
		}
		full_line = get_extract_line(line, buffer, stat_read);
	}
	return (full_line);
}

//Return a pointer to the first occurence of c
char	*gnl_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (NULL);
}

//Copies n bytes from src to dest (memories area may overlap)
void	*gnl_memmove(void *dest, const void *src, size_t n)
{
	char	*output;
	size_t	i;

	if (!dest)
		return (NULL);
	output = (char *)dest;
	i = 0;
	while (i < n)
	{
		output[i] = *((char *)src + i);
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		output[i] = '\0';
		i++;
	}
	return (output);
}
