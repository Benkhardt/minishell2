/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:53:00 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 19:06:36 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Copies up to size-1 caractere from src to dst and return (len_src)
* Take the full size of the buffer and garantee to NULL-Terminate the result
* src must be NULL terminated
* nb of copied bytes from src = size - len_dst -1. Digit at size = '\0'
* if size = 0, does not copy anything and return (len_src)
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	if (!src || !dst)
		return (0);
	len_src = ft_strlen(src);
	if (size > 0)
	{
		if (len_src >= size)
			i = size - 1;
		else
			i = len_src;
		ft_memcpy(dst, src, i);
		dst[i] = '\0';
	}
	return (len_src);
}
