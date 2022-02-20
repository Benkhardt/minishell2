/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:53:00 by flormich          #+#    #+#             */
/*   Updated: 2021/08/15 20:55:19 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Find the first occurence of little in big
* Return a pointer to the first character of little in big
* If little is empty: return big
* If no occurence: return NULL
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	len_little;

	len_little = ft_strlen(little);
	if (len_little > len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while ((i < len - len_little + 1) && (big[i] != '\0'))
	{
		j = 0;
		while ((big[i + j] == little[j]) && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
