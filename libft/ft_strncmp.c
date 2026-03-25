/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:02:11 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 12:44:55 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	int					diff;
	const unsigned char	*ucs1;
	const unsigned char	*ucs2;

	i = 0;
	ucs1 = (const unsigned char *)s1;
	ucs2 = (const unsigned char *)s2;
	while ((ucs1[i] || ucs2[i]) && i < n)
	{
		diff = (ucs1)[i] - (ucs2)[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char *s1 = "abcdef";
	char *s2 = "abcdd";
	printf("%d\n", ft_strncmp(s1, s2, 6));
}
*/