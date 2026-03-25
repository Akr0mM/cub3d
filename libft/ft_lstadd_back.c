/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:15:26 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 12:07:28 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
#include <stdio.h>
int	main()
{
	t_list	*first = ft_lstnew("1");

	first->next = ft_lstnew("2");
	first->next->next = ft_lstnew("3");
	first->next->next->next = ft_lstnew("4");
	first->next->next->next->next = ft_lstnew("5");

	ft_lstadd_back(&first, ft_lstnew("last"));

	printf("%s\n", (char *)ft_lstlast(first)->content);
}
*/