/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:55:54 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 10:55:17 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	printf("%d %d %d %d %d", ft_isprint(' '), ft_isprint('8'), ft_isprint('~'),
		ft_isprint('\0'), ft_isprint(127));
}
*/