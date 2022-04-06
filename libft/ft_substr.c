
#include "libft.h"

/*
* Extract len characters from s, starting from start
* Create a new string and return it as a pointer
* Return an empty pointer if start > len_s
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*extract;
	size_t	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	extract = ft_calloc(len + 1, sizeof(char));
	if (! extract)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		extract[i] = s[start + i];
		i++;
	}
	return (extract);
}
