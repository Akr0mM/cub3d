/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:16:53 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 19:36:00 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
#include <string.h>
void	f(void *content)
{
	((char *)content)[0] += 1;
}

int	main()
{
	t_list *first = ft_lstnew(strdup("1"));
	first->next = ft_lstnew(strdup("2"));
	first->next->next = ft_lstnew(strdup("3"));

	printf("%s %s %s\n", (char *)first->content, (char *)first->next->content,
		(char *)first->next->next->content);
	ft_lstiter(first, f);
	printf("%s %s %s\n", (char *)first->content, (char *)first->next->content,
		(char *)first->next->next->content);
}
*/