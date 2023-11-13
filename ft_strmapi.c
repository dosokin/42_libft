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

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		lens;
	int		i;
	char	*ss;

	if (s == NULL)
		return (NULL);
	lens = ft_strlen((char *)s);
	ss = malloc((lens + 1) * sizeof(char));
	if (!ss)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ss[i] = f(i, s[i]);
		i++;
	}
	ss[i] = 0;
	return (ss);
}
