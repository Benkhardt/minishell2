
#include "libft.h"

/*
* Add an already existing element at the end of the list
*/

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cur_last;

	if (new)
	{
		if (*alst == NULL)
			*alst = new ;
		else
		{
			cur_last = ft_lstlast(*alst);
			cur_last->next = new;
		}
	}
}
