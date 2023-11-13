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
#include <stdlib.h>
#include "libft.h"

static int	len(int n)
{
	int	l;

	l = 1;
	while (n / 10 != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

static char	*intmincase(void)
{
	int		i;
	char	*v;
	char	*s;

	i = 0;
	v = "-2147483648";
	s = malloc(12 * sizeof(char));
	if (!s)
		return (NULL);
	while (i < 11)
	{
		s[i] = v[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

static char	*stepnegatif(int n)
{
	char	*s;
	int		l;

	l = len(-n);
	n = -n;
	s = malloc((l + 2) * sizeof(char));
	if (!s)
		return (NULL);
	s[l + 1] = 0;
	while (l > 0)
	{
		s[l] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	s[0] = '-';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		l;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (intmincase());
	if (n < 0)
		return (stepnegatif(n));
	l = len(n);
	s = malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s[l] = 0;
	while (l > 0)
	{
		s[l - 1] = (n % 10) + '0';
		n = n / 10;
		l--;
	}
	return (s);
}
