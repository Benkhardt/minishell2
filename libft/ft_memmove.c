/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 11:49:21 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 18:07:43 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Copies n bytes from src to dest (memories area may overlap)
* return a pointer to dest
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*output;
	char	*input;
	size_t	i;

	if (!dest)
		return (NULL);
	output = (char *)dest;
	input = (char *)src;
	if (input < output)
	{
		while (n > 0)
		{
			n--;
			output[n] = input[n];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		output[i] = input[i];
		i++;
	}
	return (dest);
}
