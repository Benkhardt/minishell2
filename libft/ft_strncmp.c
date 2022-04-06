
#include "libft.h"

/*
* Compares n bytes of the strings s1 and s2
* return (s1 - s2) if a difference was found
* or return 0 if both strings are the same
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
