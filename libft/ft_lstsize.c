
#include "libft.h"

/*
* Return the number of element of the list
*/

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 1;
		while ((lst->next) != NULL)
		{
			lst = lst->next;
			i++;
		}
		return (i);
	}
	return (0);
}
