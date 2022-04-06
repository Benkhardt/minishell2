
#include "libft.h"

/*
* Create (allocate memory) a new element for the list
* Can be put at the end with ft_lstaddback after creation
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	mylist = (t_list *)malloc(sizeof(t_list));
	if (mylist)
	{
		mylist->content = content;
		mylist->next = NULL;
		return (mylist);
	}
	return (NULL);
}
