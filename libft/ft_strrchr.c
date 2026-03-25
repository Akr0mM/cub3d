/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:58:40 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 12:04:51 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
		i++;
	if (uc == '\0')
		return ((char *)s + i);
	i--;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char *a = "aaccddeeff";

	printf("%s\n", ft_strrchr(a, 'd'));
}
*/