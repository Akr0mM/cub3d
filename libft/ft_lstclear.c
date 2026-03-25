/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:17:12 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 15:17:09 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		next_node = node->next;
		ft_lstdelone(node, del);
		node = next_node;
	}
	*lst = NULL;
}

/*
#include <stdio.h>
#include <string.h>
void	del(void *content)
{
	free(content);
}
int	main()
{
	t_list	*first = ft_lstnew(strdup("1"));
	first->next = ft_lstnew(strdup("2"));
	first->next->next = ft_lstnew(strdup("3"));
	first->next->next->next = ft_lstnew(strdup("4"));
	first->next->next->next->next = ft_lstnew(strdup("5"));

	ft_lstclear(&first->next->next, &del);
	printf("%d\n", ft_lstsize(first));
}
*/