/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:55:03 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 10:55:07 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d %d %d %d %d\n", ft_isascii('\0'), ft_isascii('\r'),
		ft_isascii(127), ft_isascii(-1), ft_isascii(128));
}
*/