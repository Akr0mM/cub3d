/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloi <eloi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 15:20:25 by mfaivre           #+#    #+#             */
/*   Updated: 2026/02/17 13:42:51 by eloi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s, int n)
{
	size_t	s_len;
	size_t	i;
	char	*s_dup;

	if (n < 0)
		return (NULL);
	if ((size_t)n < ft_strlen(s))
		s_len = n;
	else
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
