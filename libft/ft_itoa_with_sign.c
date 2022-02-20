/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_with_sign.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:46:10 by flormich          #+#    #+#             */
/*   Updated: 2021/07/18 22:20:28 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert an integer in a string INKLUSIV the sign passed as parameter
** usually + oder space (printf) - also - if negativ nb
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

static int	ft_treat_negatif(char *s, int *i)
{
	if (*i < 0)
	{
		*s = '-';
		*i = -1 * (*i);
		return (-1);
	}
	return (1);
}

static int	ft_power(int i)
{
	if (i == 0)
		return (1);
	return (10 * ft_power (i - 1));
}

static void	ft_string_nb(char *s, int n, int loop, char sign)
{
	int		pwd;
	int		i;

	if (sign != '\0')
	{
		s[0] = sign;
		i = 1;
	}
	else
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

char	*ft_itoa_with_sign(int n, char sign)
{
	char	*s;
	char	*s_deb;
	int		loop;
	int		*ptr_n;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	ptr_n = &n;
	s = (char *)ft_calloc(13, sizeof(char));
	if (!s)
		return (NULL);
	s_deb = s;
	if (ft_treat_negatif(s, ptr_n) == -1)
	{
		s++;
		sign = '\0';
	}
	loop = ft_count_loop(n);
	ft_string_nb(s, n, loop, sign);
	return (s_deb);
}
