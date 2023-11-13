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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	lendst = ft_strlen((const char *)dst);
	if (lendst >= size)
		return (size + lensrc);
	i = 0;
	while (src[i] && size - 1 > (lendst + i))
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = 0;
	return (lendst + lensrc);
}
