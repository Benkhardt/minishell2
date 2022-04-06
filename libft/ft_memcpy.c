
#include "libft.h"

/*
* Copies n bytes of the memory pointed by src to dest
* Memories areas MUST NOT overlap (if overlap use memmove)
* return a pointer to dest
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*output;
	unsigned char	*input;

	output = (unsigned char *)dest;
	input = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		output[i] = input[i];
		i++;
	}
	return ((void *)output);
}
