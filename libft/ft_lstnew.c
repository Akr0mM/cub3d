/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:56:39 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 20:05:23 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

/*
#include <stdio.h>
int	main()
{
	t_list *first = ft_lstnew("1");
	first->next = ft_lstnew("2");
	first->next->next = ft_lstnew("3");
	first->next->next->next = ft_lstnew("4");

	printf("%d\n", ft_lstsize(first));
}
*/