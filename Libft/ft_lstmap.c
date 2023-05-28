/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:24:14 by daumis            #+#    #+#             */
/*   Updated: 2022/11/15 23:23:52 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_free(t_list *start, void (*del)(void *))
{
	ft_lstclear(&start, del);
	return (start);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*start;

	if (!lst)
		return (0);
	nlst = (t_list *)malloc(sizeof(t_list));
	if (!nlst)
		return (0);
	nlst->content = f(lst->content);
	nlst->next = NULL;
	start = nlst;
	lst = lst->next;
	while (lst)
	{
		nlst->next = (t_list *)malloc(sizeof(t_list));
		if (!nlst)
			return (ft_free(start, del));
		nlst = nlst->next;
		nlst->content = f(lst->content);
		nlst->next = NULL;
		lst = lst->next;
	}
	return (start);
}
