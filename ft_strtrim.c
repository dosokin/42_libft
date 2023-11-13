/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/10/30 11:24:07 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	ischarinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	indexation(char const *s1, char const *set, int v)
{
	int	i;

	if (v == 1)
	{
		i = 0;
		while (ischarinset(s1[i], set) && s1[i])
			i++;
		return (i);
	}
	else
	{
		i = ft_strlen(s1) - 1;
		while (ischarinset(s1[i], set))
			i--;
		return (i);
	}
}

static char	*duplicate(char const *s, int len)
{
	int		i;
	char	*r;

	i = 0;
	r = (ft_calloc((len + 1), (sizeof(char))));
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	return (r);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		k;
	char	*r;
	int		debut;

	i = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	if (s1[i] == 0)
		return (ft_calloc(1, (sizeof(char))));
	if (set[i] == 0)
		return (duplicate(s1, ft_strlen(s1)));
	debut = indexation(s1, set, 1);
	if (s1[debut] == 0)
		return (ft_calloc(1, (sizeof(char))));
	i = indexation(s1, set, 2);
	r = ft_calloc((i - debut + 2), sizeof(char));
	if (!r)
		return (NULL);
	k = 0;
	while (debut <= i)
		r[k++] = s1[debut++];
	return (r);
}
