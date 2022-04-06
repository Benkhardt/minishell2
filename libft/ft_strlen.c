
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
