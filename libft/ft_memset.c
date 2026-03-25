/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:59:37 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/07 11:38:13 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <string.h>
#include <stdio.h>
int main()
{
	char s[10] = "abcdefghij";
	printf("%s\n", (char *)memset(s, 'N', 10));
	printf("%s\n", (char *)ft_memset(s, 'N', 10));
}
*/