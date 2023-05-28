/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:09:47 by daumis            #+#    #+#             */
/*   Updated: 2022/11/21 18:03:19 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab, int i)
{
	i--;
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

static char	*fill_tab(char const *s, char sep)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != sep)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	wdcount(char const *s, char sep)
{
	size_t	i;
	int		swth;
	int		count;

	i = 0;
	count = 0;
	swth = 0;
	while (s[i])
	{
		if (s[i] == sep && swth == 1)
			swth = 0;
		else if (s[i] != sep && swth == 0)
		{
			count++;
			swth = 1;
		}
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**final_tab;
	int		nb_arr;
	int		i;

	nb_arr = 0;
	i = 0;
	final_tab = malloc(sizeof(char *) * (wdcount(s, c) + 1));
	if (!final_tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			final_tab[nb_arr] = fill_tab(s + i, c);
			if (final_tab[nb_arr] == NULL)
				return (ft_free(final_tab, nb_arr));
			nb_arr++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	final_tab[nb_arr] = 0;
	return (final_tab);
}
