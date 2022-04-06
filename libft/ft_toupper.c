
#include "libft.h"

/*
* Converts letters to their uppercase
*/

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	else
		return (c);
}
