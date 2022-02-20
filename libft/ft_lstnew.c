/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flormich <flormich@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:35:14 by flormich          #+#    #+#             */
/*   Updated: 2021/06/06 17:51:28 by flormich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
