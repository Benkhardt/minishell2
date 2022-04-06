
#include "libft.h"

/*
** Delete one element of the list - inklusiv free
** Suppose the re-link has been made before
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
	lst = NULL;
}
