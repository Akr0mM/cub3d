/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:48:01 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 11:31:26 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	if (size != 0 && nmemb > (size_t)-1 / size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return ((void *)alloc);
}

/*
#include <stdio.h>
int	main()
{
	int *tab = ft_calloc(10, sizeof(int));
	int i = 0;
	while (i < 10)
	{
		printf("%d\n", tab[i]);
		i++;
	}
}
*/