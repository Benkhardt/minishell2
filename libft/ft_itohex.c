/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:31:45 by flormich          #+#    #+#             */
/*   Updated: 2021/07/21 15:43:30 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add 0x or 0X prefixe if needed
static char	*ft_add_prefix(char*hexa, char const *prefix)
{
	char	*adr;

	adr = hexa;
	hexa = ft_strjoin(prefix, (char const *)hexa);
	free(adr);
	return (hexa);
}

// Convert unsigned long long in hexadecimal
// Begin from the less significant digit so digit + hexa_str
char	*ft_itohex(unsigned long long nb, char big_small, char const *prefix)
{
	char	*conv;
	char	digit[2];
	char	*hexa;
	char	*adr;

	hexa = ft_calloc(1, sizeof(char));
	conv = "0123456789abcdef";
	while (nb > 0 || (nb % 16 > 0))
	{
		if (big_small == 'X')
			digit[0] = ft_toupper(*(&conv[nb % 16]));
		else
			digit[0] = *(&conv[nb % 16]);
		digit[1] = '\0';
		adr = hexa;
		hexa = ft_strjoin(digit, (char const *)hexa);
		free(adr);
		nb = nb / 16;
	}
	if (prefix && hexa)
		hexa = ft_add_prefix(hexa, prefix);
	return (hexa);
}
