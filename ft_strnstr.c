/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosokin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:23:14 by dosokin           #+#    #+#             */
/*   Updated: 2023/10/30 20:22:56 by dosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	check(const char *big, const char *little, size_t len, int i)
{
	size_t	l;

	l = 0;
	while (little[l])
	{
		if (big[i] == little[l])
		{
			i++;
			l++;
		}
		else
			return (0);
	}
	if (l <= len)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (ft_strlen((char *)big) < ft_strlen((char *)little))
		return (NULL);
	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	while (big[i] && len > 0)
	{
		if (big[i] != little[j])
			i++;
		else
		{
			if ((check(big, little, len, i)) == 1)
				return ((char *)&big[i]);
			i++;
		}
		len--;
	}
	return (0);
}
