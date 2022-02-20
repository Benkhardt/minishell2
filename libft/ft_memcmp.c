/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:39:45 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 18:01:09 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Compares n bytes of the memory pointed by s1 and s2
* return (s1 - s2) if a difference was found
* or return 0 if both memories match
* Both memories s1 and s2 are interpreted as (unsigned char)
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ch1;
	const unsigned char	*ch2;
	size_t				i;

	ch1 = (const unsigned char *)s1;
	ch2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ch1[i] != ch2[i])
			return (ch1[i] - ch2[i]);
		i++;
	}
	return (0);
}
