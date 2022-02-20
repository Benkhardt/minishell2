/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:32:56 by flormich          #+#    #+#             */
/*   Updated: 2021/10/24 00:30:21 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Remove the character from the set from the begining and end of the string
*/

static int	ft_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		else
			i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;
	int		i;

	if (!set)
		return ((char *)s1);
	start = 0;
	while (ft_is_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (ft_is_in_set(s1[end - 1], set) == 1)
		end--;
	if (end < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	trim = (char *)ft_calloc(((end - start) + 2), sizeof(*s1));
	if (! trim)
		return (NULL);
	i = 0;
	while (start + i <= end - 1)
	{
		trim[i] = s1[start + i];
		i++;
	}
	return (trim);
}
