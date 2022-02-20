/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:49:36 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 17:53:20 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Copy no more than n bytes from src to dst (STOP when c is found)
* return a pointer to dest pos c + 1
* or return NULL if c was not found
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*output;
	unsigned char	*input;

	if (!src || !dest)
		return (NULL);
	output = (unsigned char *)dest;
	input = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		output[i] = input[i];
		if (input[i] == (unsigned char)c)
			return ((void *)(output + i + 1));
		i++;
	}
	return (NULL);
}
