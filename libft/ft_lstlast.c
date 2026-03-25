/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:16:34 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 11:49:23 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
int	main()
{
	t_list *first = ft_lstnew("first");
	first->next = ft_lstnew("second");
	first->next->next = ft_lstnew("last");

	printf("%s\n", (char *)ft_lstlast(first)->content);
}
*/