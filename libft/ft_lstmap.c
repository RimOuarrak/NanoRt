/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rouarrak <rouarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:19:31 by rouarrak          #+#    #+#             */
/*   Updated: 2022/10/20 17:47:46 by rouarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*t;	

	t = NULL;
	if (!lst)
		return (NULL);
	while (lst != NULL)
	{
		l = ft_lstnew((*f)(lst -> content));
		if (!l)
		{
			ft_lstclear (&t, del);
			return (NULL);
		}
		ft_lstadd_back(&t, l);
		lst = lst -> next;
	}
	return (t);
}
