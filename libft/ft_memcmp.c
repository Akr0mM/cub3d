/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:42:58 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 11:26:33 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	int					diff;
	const unsigned char	*uc_s1;
	const unsigned char	*uc_s2;

	i = 0;
	uc_s1 = (const unsigned char *)s1;
	uc_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		diff = uc_s1[i] - uc_s2[i];
		if (diff != 0)
			return (diff);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char *s1 = "abcde";
	char *s2 = "abce";

	printf("%d\n", memcmp(s1, s2, 5));
	printf("%d\n", ft_memcmp(s1, s2, 5));
}
*/