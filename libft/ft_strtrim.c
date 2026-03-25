/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:26:25 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/11 12:59:55 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isset(char const c, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_strcut(char const *s, char *new_string, size_t start,
	size_t end)
{
	size_t	i;

	i = 0;
	while (i <= end - start)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

static char	*empty_string(void)
{
	char	*string;

	string = malloc(1);
	if (!string)
		return (NULL);
	string[0] = '\0';
	return (string);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new_string;

	if (s1[0] == '\0')
		return (empty_string());
	i = 0;
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i > 0 && ft_isset(s1[i], set))
		i--;
	end = i;
	if (start > end)
		return (empty_string());
	new_string = malloc((end - start + 2) * sizeof(char));
	if (!new_string)
		return (NULL);
	return (ft_strcut(s1, new_string, start, end));
}

/*
#include <stdio.h>
int main()
{
	char *s = " k bds askjdh1khjbakuh20h kjsbd  ";

	printf("%s\n", ft_strtrim(s, " kjsbd"));
}
*/