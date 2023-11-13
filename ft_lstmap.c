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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*storage;
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (NULL);
	current = lst;
	storage = NULL;
	while (current)
	{
		new = ft_lstnew(f(current->content));
		if (new == NULL)
		{
			ft_lstclear(&storage, del);
			return (NULL);
		}
		ft_lstadd_back(&storage, new);
		current = current->next;
	}
	return (storage);
}
