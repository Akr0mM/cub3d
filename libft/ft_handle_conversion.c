/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:40:27 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:08:30 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_conversion(const char c, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_flags(va_arg(args, int), flags);
	else if (c == 's')
		count += ft_putstr(va_arg(args, char *), &flags);
	else if (c == 'p')
		count += ft_putptr(va_arg(args, void *), flags);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_putunsignednbr(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_putlowerx(va_arg(args, unsigned int), flags);
	else if (c == 'X')
		count += ft_putupperx(va_arg(args, unsigned int), flags);
	else if (c == '%')
		count += ft_putchar('%');
	if (flags.left_justify)
		count += ft_add_left_justify(count, flags);
	return (count);
}

int	ft_add_left_justify(int len, t_flags flags)
{
	int	count;

	count = 0;
	while (flags.left_justify > len)
	{
		count += ft_putchar(' ');
		flags.left_justify--;
	}
	return (count);
}

void	ft_check_plus(t_flags *flags)
{
	flags->plus = 1;
	flags->blank = 0;
}
