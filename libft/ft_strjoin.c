/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:14:54 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 11:37:11 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_string;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc((len1 + len2 + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		new_string[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		new_string[i] = s2[i - len1];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

/*
#include <stdio.h>
int	main()
{
	char *s1 = "abdef";
	char *s2 = "wxyz";

	printf("%s\n", ft_strjoin(s1, s2));
}
*/