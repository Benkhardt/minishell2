/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:46:10 by flormich          #+#    #+#             */
/*   Updated: 2021/07/16 18:14:53 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Convert an unsigned integer in a string
*/

static int	ft_count_loop( unsigned int nb)
{
	unsigned int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	ft_power(unsigned int i)
{
	if (i == 0)
		return (1);
	return (10 * ft_power (i - 1));
}

static void	ft_string_nb(char *s, unsigned int n, int loop)
{
	unsigned int		pwd;
	unsigned int		i;

	i = 0;
	while (loop > 0)
	{
		pwd = ft_power(loop - 1);
		s[i] = (n / pwd) + 48;
		i++;
		loop--;
		n = n - (n / pwd) * pwd;
	}
	s[i] = '\0';
}

char	*ft_itoa_unsigned_int(unsigned int n)
{
	char			*s;
	char			*s_deb;
	unsigned int	loop;

	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)malloc(sizeof(char) * 12);
	if (!s)
		return (NULL);
	s_deb = s;
	loop = ft_count_loop(n);
	ft_string_nb(s, n, loop);
	return (s_deb);
}
