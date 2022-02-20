/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_without_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:46:10 by flormich          #+#    #+#             */
/*   Updated: 2021/07/18 22:21:21 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert an integer in a string WITHOUT the sign at the begining
** Made for printf to allow to padd 0 between sign and absolut number
*/

static int	ft_count_loop( int nb)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static int	ft_power(int i)
{
	if (i == 0)
		return (1);
	return (10 * ft_power (i - 1));
}

static void	ft_string_nb(char *s, int n, int loop)
{
	int		pwd;
	int		i;

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

char	*ft_itoa_without_sign(int n)
{
	char	*s;
	char	*s_deb;
	int		loop;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = (char *)ft_calloc(13, sizeof(char));
	if (!s)
		return (NULL);
	s_deb = s;
	if (n < 0)
		n = (-1 * n);
	loop = ft_count_loop(n);
	ft_string_nb(s, n, loop);
	return (s_deb);
}
