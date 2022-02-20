/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:28:05 by flormich          #+#    #+#             */
/*   Updated: 2021/08/18 17:35:32 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Split a string on sevral strings according to the delimiter
** Return a ** to the array with the adress of the strings
** Last adress is a NULL pointer
*/

static char	**ft_create_ar(const char *s, char c)
{
	int	nb;

	nb = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			nb++;
			while (*s && *s != c)
				s++;
		}
	}
	return ((char **)ft_calloc(nb + 1, sizeof(s)));
}

static int	ft_find_str_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_extract_string(char const *s, char c)
{
	char	*str;
	int		i;

	i = ft_find_str_len(s, c);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	while (*s == c && *s != '\0')
		s++;
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	int		j;

	if (!s)
		return (NULL);
	ar = ft_create_ar(s, c);
	if (!ar)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != '\0')
		{
			ar[j] = ft_extract_string(s, c);
			if (ar[j] == NULL)
				return (NULL);
			while (*s != c && *s != '\0')
				s++;
			j++;
		}
	}
	ar[j] = 0;
	return (ar);
}
