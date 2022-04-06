
#include "libft.h"

/*
* Apply a fonction to the content of all element of the list
* Starting from element *lst
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
