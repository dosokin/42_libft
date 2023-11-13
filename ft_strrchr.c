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

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*l;

	i = 0;
	l = 0;
	while (s[i])
	{
		if (s[i] == ((unsigned char)c))
		{
			l = ((char *)&s[i]);
			i++;
		}
		else
			i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (l);
}
