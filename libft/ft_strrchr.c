/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:11:12 by flormich          #+#    #+#             */
/*   Updated: 2021/07/31 14:03:07 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Search for the last ocurence of c in a string s
* Return a pointer to the last occurence of c
* Return NULL if c is not found
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		n;
	int		i;

	str = (char *)s;
	n = ft_strlen(str);
	i = 0;
	while (n >= 0)
	{
		if (str[n] == c)
		{
			while (i < n)
			{
				str++;
				i++;
			}
			return (str);
		}
		n--;
	}
	return (NULL);
}
