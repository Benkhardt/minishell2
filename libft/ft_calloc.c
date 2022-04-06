
#include "libft.h"

/*
* Allocate memory for an array of nmemb elements of size bytes each
* This memory is set to '\0'
* If nmemb or size = 0 => return a pointer of size 0
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	char	*temp;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return ((void *)malloc(0));
	p = (void *)malloc((size * nmemb));
	if (!p)
		return (NULL);
	temp = (char *)p;
	i = 0;
	while (i < (size * nmemb))
	{
		temp[i] = '\0';
		i++;
	}
	return (p);
}
