/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:50:31 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 12:02:34 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned int	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i])
	{
		if ((unsigned char)s[i] == uc)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)s[i] == uc)
		return ((char *)s + i);
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	char *a = "aaccddeeff";

	printf("%s\n", ft_strchr(a, 'd'));
}
*/