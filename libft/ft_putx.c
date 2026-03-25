/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:55:47 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:09:33 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlowerx(unsigned int hexa, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count += ft_add_char_hexa((unsigned long)hexa, &flags, ' ');
	if (flags.hash && hexa)
	{
		ft_putstr_fd("0x", 1);
		flags.hash = 0;
		flags.zeros -= 2;
		count += 2;
	}
	if (flags.zeros || flags.precision)
		count += ft_add_char_hexa((unsigned long)hexa, &flags, '0');
	if (flags.precision_is_zero && hexa == 0)
		return (count);
	if (hexa >= 16)
		count += ft_putlowerx(hexa / 16, flags);
	count += ft_putchar("0123456789abcdef"[hexa % 16]);
	return (count);
}

int	ft_putupperx(unsigned int hexa, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count += ft_add_char_hexa((unsigned long)hexa, &flags, ' ');
	if (flags.hash && hexa)
	{
		ft_putstr_fd("0X", 1);
		flags.hash = 0;
		flags.zeros -= 2;
		count += 2;
	}
	if (flags.zeros || flags.precision)
		count += ft_add_char_hexa((unsigned long)hexa, &flags, '0');
	if (flags.precision_is_zero && hexa == 0)
		return (count);
	if (hexa >= 16)
		count += ft_putupperx(hexa / 16, flags);
	count += ft_putchar("0123456789ABCDEF"[hexa % 16]);
	return (count);
}

int	ft_add_char_hexa(unsigned long hexa, t_flags *flags, char c)
{
	int	count;
	int	hexa_len;
	int	*value;

	count = 0;
	hexa_len = ft_hexalen(hexa);
	if (c == '0' && flags->precision)
		value = &(flags->precision);
	else if (c == '0' && flags->zeros)
		value = &(flags->zeros);
	if (c == ' ')
		value = &(flags->width);
	if (c == ' ' && flags->hash)
		hexa_len += 2;
	if (c == ' ' && flags->precision >= hexa_len)
		*value -= flags->precision - hexa_len;
	while (*value > hexa_len
		|| (flags->precision_is_zero && hexa == 0 && *value > 0)
		|| (*value == flags->precision && *value > hexa_len))
	{
		count += ft_putchar(c);
		(*value)--;
	}
	*value = 0;
	return (count);
}

int	ft_hexalen(unsigned long nbr)
{
	int	len;

	len = 1;
	if (nbr >= 16)
		len += ft_hexalen(nbr / 16);
	return (len);
}
