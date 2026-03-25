/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:56:22 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 10:55:01 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d %d %d %d %d\n", ft_isalpha('a'), ft_isalpha('z'),
		ft_isalpha('B'), ft_isalpha('3'), ft_isalpha('\0'));
}
*/