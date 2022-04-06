
#include "libft.h"

/*
**	Put '\0' in n bytes of the memory pointed by s
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		((char *)(s))[i] = '\0';
		i++;
	}
}
