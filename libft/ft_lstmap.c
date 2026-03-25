/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:15:48 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 20:03:32 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clear_list(t_list **new_list, void **content,
		void (*del)(void *))
{
	if (content && *content)
		del(*content);
	if (new_list && *new_list)
		ft_lstclear(new_list, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!f || !del || !lst)
		return (NULL);
	new_content = f(lst->content);
	new_list = ft_lstnew(new_content);
	if (!new_list)
		return (clear_list(&new_list, &new_content, del));
	lst = lst->next;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (clear_list(&new_list, &new_content, del));
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	const char *s = content;
    char buf[2];
    buf[0] = s[0] + 1;
    buf[1] = '\0';
    return strdup(buf);
}

int	main()
{
	t_list *first = ft_lstnew(strdup("1"));
	first->next = ft_lstnew(strdup("2"));
	first->next->next = ft_lstnew(strdup("3"));

	t_list *new_first = ft_lstmap(first, f, del);

	printf("%s %s %s\n", (char *)first->content, (char *)first->next->content,
		(char *)first->next->next->content);
	printf("%s %s %s\n", (char *)new_first->content,
		(char *)new_first->next->content,
		(char *)new_first->next->next->content);
}
*/