/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:05:34 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 14:33:29 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>
int	main()
{
	t_list *first = ft_lstnew("first");

	ft_lstadd_front(&first, ft_lstnew("new first"));
	printf("%s\n", (char *)first->content);
	printf("%s\n", (char *)first->next->content);
}
*/