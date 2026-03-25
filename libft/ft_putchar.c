/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:56:37 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:10:01 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_putchar_flags(char c, t_flags flags)
{
	int	count;

	count = 0;
	while (flags.width > 1)
	{
		count += ft_putchar(' ');
		flags.width--;
	}
	count += ft_putchar(c);
	return (count);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
