/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:53:57 by flormich          #+#    #+#             */
/*   Updated: 2021/07/16 21:14:46 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert a string to an integer
** get ride of the first space
*/

int	ft_atoi(const char *ptr)
{
	int		plus_minus;
	long	nb;
	long	i;

	i = 0;
	nb = 0;
	plus_minus = 1;
	while (ptr[i] != '\0' && (ptr[i] == 32 || (ptr[i] >= 9 && ptr[i] <= 13)))
		i++;
	if (ptr[i] != '\0' && ptr[i] == '-')
	{
		plus_minus = -1;
		i++;
	}
	else if (ptr[i] == '+')
		i++;
	while (ft_isdigit(ptr[i]) && ptr[i] != '\0')
	{
		nb = (nb * 10) + (ptr[i] - 48);
		i++;
	}
	if (plus_minus == -1)
		return (-nb);
	return (nb);
}
