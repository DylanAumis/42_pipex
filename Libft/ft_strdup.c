/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:48:23 by dylan             #+#    #+#             */
/*   Updated: 2022/11/12 11:31:00 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	lensrc;
	size_t	i;
	char	*dupsrc;

	lensrc = ft_strlen(s);
	i = 0;
	dupsrc = malloc(lensrc * sizeof(const char) + 1);
	if (!dupsrc)
		return (NULL);
	while (s[i])
	{
		dupsrc[i] = s[i];
		i++;
	}
	dupsrc[i] = '\0';
	return (dupsrc);
}
