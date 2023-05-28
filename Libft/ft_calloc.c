/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:49:05 by dylan             #+#    #+#             */
/*   Updated: 2022/11/21 18:58:50 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if (nmemb && (nmemb * size / nmemb) != size)
		return (NULL);
	if (size == 0 || nmemb == 0)
	{
		size = 1;
		nmemb = 1;
	}
	ptr = (unsigned char *)malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_memset(ptr, 0, (size * nmemb));
	return (ptr);
}
