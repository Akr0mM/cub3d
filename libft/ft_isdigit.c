/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:55:33 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 10:55:12 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d %d %d %d %d", ft_isdigit('0'), ft_isdigit('1')
		ft_isdigit('9'), ft_isdigit(9), ft_isdigit('\t'));
}
*/