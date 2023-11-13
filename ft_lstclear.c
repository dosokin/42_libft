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

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*storage;
	t_list	*stornext;

	if (lst == NULL || del == NULL)
		return ;
	storage = *lst;
	stornext = storage->next;
	while (stornext)
	{
		del(storage->content);
		free(storage);
		storage = stornext;
		stornext = stornext->next;
	}
	del(storage->content);
	free(storage);
	*lst = NULL;
}
