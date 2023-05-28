/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:26:58 by daumis            #+#    #+#             */
/*   Updated: 2022/11/15 16:20:01 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*membre;

	membre = (t_list *)malloc(sizeof(t_list));
	if (!membre)
		return (0);
	membre->content = content;
	membre->next = 0;
	return (membre);
}
