/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:58:22 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 12:39:31 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*new_string;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	new_string = malloc((s_len + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	while (i < s_len)
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*
#include <stdio.h>
char	f(unsigned int i, char c)
{
	return (c + i);
}
int	main()
{
	char *s = "aaaaa";
	printf("%s\n", ft_strmapi(s, f));
}
*/