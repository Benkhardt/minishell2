/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:21:36 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 19:13:29 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Copies the string s
* Apply a given function to each of its characters
* Return a pointer to the copied string
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_work;
	int		i;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	s_work = (char *)ft_calloc(i + 1, sizeof(char));
	if (!s_work)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s_work[i] = (*f)(i, s[i]);
		i++;
	}
	return (s_work);
}
