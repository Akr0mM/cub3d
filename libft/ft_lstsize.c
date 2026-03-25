/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:12:31 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 12:19:06 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
#include <stdio.h>
int	main()
{
	t_list	*first = ft_lstnew("first");

	first->next = ft_lstnew("next");
	first->next->next = ft_lstnew("next");
	first->next->next->next = ft_lstnew("next");
	first->next->next->next->next = ft_lstnew("next");
	printf("%d\n", ft_lstsize(first));
}
*/