
#include "libft.h"

/*
* Copy no more than n bytes from src to dst (STOP when c is found)
* return a pointer to dest pos c + 1
* or return NULL if c was not found
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*output;
	unsigned char	*input;

	if (!src || !dest)
		return (NULL);
	output = (unsigned char *)dest;
	input = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		output[i] = input[i];
		if (input[i] == (unsigned char)c)
			return ((void *)(output + i + 1));
		i++;
	}
	return (NULL);
}
