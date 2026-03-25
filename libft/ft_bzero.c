/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:57:32 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/10 14:16:27 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*
#include <strings.h>
#include <stdio.h>
int main()
{
	char s[5] = "abcde"; 
	char t[5] = "abcde";

	bzero(s + 2, 2);
	ft_bzero(t + 2, 2);
	printf("%s\n", s);
	printf("%s\n", t);
}
*/