/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:00:14 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 17:49:32 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Copy the list starting from *lst
* Apply a fonction to the content
* Delete the copied list in case of pb
* New element is created in ft_lstnew
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*new;

	if (!lst)
		return (NULL);
	cpy = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new)
		{
			ft_lstadd_back(&cpy, new);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&cpy, (*del));
			return (NULL);
		}
	}
	return (cpy);
}
