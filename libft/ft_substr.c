/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:00:25 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 13:11:47 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strlen_max(const char *s, size_t len)
{
	size_t	i;

	i = 0;
	while (s[i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*s_sub;

	if (!s || start >= ft_strlen(s))
	{
		s_sub = malloc(1);
		if (!s_sub)
			return (NULL);
		s_sub[0] = '\0';
		return (s_sub);
	}
	size = ft_strlen_max(s + start, len);
	s_sub = malloc((size + 1) * sizeof(char));
	if (!s_sub)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_sub[i] = s[start + i];
		i++;
	}
	s_sub[i] = '\0';
	return (s_sub);
}

/*
#include <stdio.h>
int	main()
{
	char	*s = "abcdef";

	printf("%s\n", ft_substr(s, 2, 65));
}
*/