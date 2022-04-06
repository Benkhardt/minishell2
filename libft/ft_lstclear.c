
#include "libft.h"

/*
* Delete all the element after the one pointed by **lst
* Free made in ft_lstdelone
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*mem_next;

	if (!lst || !(*del))
		return ;
	mem_next = (*lst)->next;
	while (*lst)
	{
		mem_next = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = mem_next;
	}
	*lst = NULL;
}
