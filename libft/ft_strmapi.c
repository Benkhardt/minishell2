
#include "libft.h"

/*
* Copies the string s
* Apply a given function to each of its characters
* Return a pointer to the copied string
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_work;
	int		i;

	if (!s || !(*f))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	s_work = (char *)ft_calloc(i + 1, sizeof(char));
	if (!s_work)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s_work[i] = (*f)(i, s[i]);
		i++;
	}
	return (s_work);
}
