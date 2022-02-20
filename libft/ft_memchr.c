/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:49:09 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 17:58:07 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Scans n bytes of the memory pointed by s for the first instance of c
* return a pointer to the matching bytes
* or return NULL if c was not found
* Both memory and c are interpreted as (unsigned char)
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)(c))
			return ((void *)(str + i));
		else
			i++;
	}
	return (NULL);
}
