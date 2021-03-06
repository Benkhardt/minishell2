
#include "libft.h"

/*
* Return a pointer to a new string which is a duplicate from s
* Return NULL if the memory allocation failed
*/

char	*ft_strdup(const char *s)
{
	char	*r;
	int		len;
	int		i;

	len = ft_strlen(s);
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (!r)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = s[i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
