/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:53:00 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 19:04:19 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Concatene some bytes of src at the end of dst and return (len_src + len_dst)
* Take the full size of the buffer and garantee to NULL-Terminate the result
* src and dst must be NULL terminated
* nb of copied bytes from src = size - len_dst -1. Digit at size = '\0'
* if size <= len_dst (incl '\0') doesn't copy anything, return (len_src + size)
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (size > len_dst)
	{
		i = 0;
		while ((i + len_dst < size - 1) && ((src[i] != '\0')))
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
		return (len_src + len_dst);
	}
	return (len_src + size);
}
