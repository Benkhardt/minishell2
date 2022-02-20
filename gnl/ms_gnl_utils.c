/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:11:16 by flormich          #+#    #+#             */
/*   Updated: 2021/11/20 11:23:55 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_libs.h"

// Find the lenght bis the next '\n'
size_t	get_lglen(const char *s)
{
	size_t	n;

	if (! s)
		return (0);
	n = 0;
	while (s[n] != '\n' && s[n] != '\0')
	{
		if (n == BUFFER_SIZE - 1)
			return (n);
		n++;
	}
	if (s[n] == '\n')
		n++;
	return (n);
}

//Extract len characters from s, starting from start
char	*gnl_substr(char const *s, size_t len)
{
	char	*extract;
	size_t	i;

	extract = ft_calloc(len + 1, sizeof(char));
	if (! extract)
		return (NULL);
	i = 0;
	while (i < len && s[i] != '\0' && s[i] != '\n')
	{
		extract[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		extract[i] = s[i];
		i++;
	}
	extract[i] = '\0';
	return (extract);
}

// Return the lengh of the string
size_t	gnl_strlen(const char *s)
{
	size_t	n;

	if (! s)
		return (0);
	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

// Put '\0' in n bytes of the memory pointed by s
void	gnl_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((char *)(s))[i] = '\0';
		i++;
	}
	if (n == 0)
		((char *)(s))[0] = '\0';
}

// Allocate memory for an array of nmemb elements of size bytes each
void	*gnl_calloc(size_t nmemb, size_t n)
{
	void	*dest;

	dest = malloc(nmemb * n);
	if (!dest)
		return (0);
	ft_bzero(dest, nmemb * n);
	return (dest);
}
