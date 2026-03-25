/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:35:21 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 11:12:48 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ucs;
	unsigned char		ucc;

	i = 0;
	ucs = (const unsigned char *)s;
	ucc = (unsigned char)c;
	while (i < n)
	{
		if (ucs[i] == ucc)
			return ((void *)(ucs + i));
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char *s = "abcdef";
	printf("%s\n", (char *)ft_memchr(s, 'c', 5));
}
*/