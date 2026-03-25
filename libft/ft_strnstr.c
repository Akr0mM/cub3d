/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:46:36 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 11:39:33 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	little_len = ft_strlen(little);
	while (big[i] && i < len)
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
		{
			j++;
			if (j == little_len)
			{
				return ((char *)big + i);
			}
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main()
{
	char *big = "abcdef";
	char *little = "cd";
	size_t len = 4;
	printf("%s\n", strnstr(big, little, len));
	printf("%s\n", ft_strnstr(big, little, len));
}
*/