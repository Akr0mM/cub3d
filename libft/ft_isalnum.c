/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:10:49 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 10:55:25 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d\n", ft_isalnum(' '));
	printf("%d\n", ft_isalnum('b'));
	printf("%d\n", ft_isalnum('c'));
	printf("%d\n", ft_isalnum('Z'));
	printf("%d\n", ft_isalnum('*'));
	printf("%d\n", ft_isalnum('3'));
	printf("%d\n", ft_isalnum('\0'));
	printf("%d\n", ft_isalnum('\r'));
}
*/