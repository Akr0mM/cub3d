/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:55:06 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 12:13:01 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	size_t	i;
	char	*s_dup;

	s_len = ft_strlen(s);
	s_dup = malloc((s_len + 1) * sizeof(char));
	if (!s_dup)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

/*
#include <stdio.h>
int	main()
{
	char *s = ft_strdup("abcdef");
	printf("%s\n", s);
	free(s);
}
*/