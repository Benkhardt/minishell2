/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 14:11:04 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 18:39:53 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Return the lengh of a string
*/

size_t	ft_strlen(const char *s)
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
