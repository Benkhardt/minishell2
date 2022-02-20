/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:32:56 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 18:50:58 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Return the result of the concatenation from s1 & s2
* Create the memory for the concatenation
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*conc;
	unsigned int	len;
	int				i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	conc = (char *)malloc(sizeof(*s1) * len);
	if (! conc)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		conc[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		conc[i] = *s2;
		i++;
		s2++;
	}
	conc[i] = '\0';
	return (conc);
}
