/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:01:22 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 12:27:37 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
	{
		return (b);
	}
	return (a);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	while (siz != 0 && src[i] && dst_len + i < siz - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (siz > dst_len)
	{
		dst[dst_len + i] = '\0';
	}
	return (ft_strlen(src) + ft_min(siz, dst_len));
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char	*a = "abc";
	char	b[6];

	b[0] = 'd';
	b[1] = 'e';
	b[2] = 'f';

	printf("%zu %s\n", ft_strlcat(b, a, 6), b);
}
*/