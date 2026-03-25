/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:55:00 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:09:26 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_add_char_unsigned(unsigned int nbr, int len,
				t_flags *flags, char c);

int	ft_putunsignednbr(unsigned int nbr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count += ft_add_char_unsigned(nbr, count, &flags, ' ');
	if (flags.zeros || flags.precision)
		count += ft_add_char_unsigned(nbr, count, &flags, '0');
	flags.blank = 0;
	flags.plus = 0;
	if (flags.precision_is_zero && nbr == 0)
		return (count);
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10, flags);
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}

static int	ft_add_char_unsigned(unsigned int nbr, int len,
	t_flags *flags, char c)
{
	int	count;
	int	nbr_len;
	int	*value;

	count = 0;
	nbr_len = ft_unsignednbrlen(nbr);
	if (c == '0' && flags->precision)
		value = &(flags->precision);
	else if (c == '0' && flags->zeros)
		value = &(flags->zeros);
	if (c == ' ')
		value = &(flags->width);
	if (c == ' ' && flags->precision >= nbr_len)
		*value -= flags->precision - nbr_len;
	while ((*value > nbr_len + len)
		|| (flags->precision_is_zero && nbr == 0 && *value > len)
		|| (*value == flags->precision && *value > nbr_len))
	{
		count += ft_putchar(c);
		(*value)--;
	}
	*value = 0;
	return (count);
}

int	ft_unsignednbrlen(unsigned int nbr)
{
	int	len;

	len = 1;
	if (nbr >= 10)
		len += ft_unsignednbrlen(nbr / 10);
	return (len);
}
