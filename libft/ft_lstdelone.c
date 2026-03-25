/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:16:16 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 17:57:16 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
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

	printf("%d\n", ft_lstsize(first));
	t_list *to_del = first->next;
	first->next = to_del->next;
	ft_lstdelone(to_del, del);
	printf("%d\n", ft_lstsize(first));
}
*/