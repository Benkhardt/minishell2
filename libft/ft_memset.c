
#include "libft.h"

/*
* Fills n bytes of the memory pointed by s with the constant byte c
* return a pointer to the memory area s
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*output;
	size_t			i;

	if (!s)
		return (NULL);
	output = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		output[i] = (unsigned char) c;
		i++;
	}
	return ((void *)output);
}
