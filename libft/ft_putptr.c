/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:52:44 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:08:58 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_puthex(unsigned long n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width > 0)
	{
		count += ft_add_char_hexa(n, &flags, ' ');
		ft_putstr_fd("0x", 1);
	}
	if (flags.zeros > 0)
		count += ft_add_char_hexa(n, &flags, '0');
	if (n >= 16)
		count += ft_puthex(n / 16, flags);
	count += ft_putchar("0123456789abcdef"[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr, t_flags flags)
{
	unsigned long	ul_ptr;

	if (!ptr)
		return (ft_putstr("(nil)", &flags));
	ul_ptr = (unsigned long)ptr;
	flags.width -= 2;
	if (flags.width <= 0)
		ft_putstr_fd("0x", 1);
	flags.zeros -= 2;
	return (ft_puthex(ul_ptr, flags) + 2);
}
