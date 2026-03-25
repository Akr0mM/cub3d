/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:54:09 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:08:51 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle_int_min(int nbr, t_flags flags);
static int	ft_add_char(int nbr, int len, t_flags *flags, char c);
static int	ft_nbrlen_flags(int nbr, t_flags *flags);

int	ft_putnbr(int nbr, t_flags flags)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
		return (ft_handle_int_min(nbr, flags));
	if (nbr >= 0 && flags.blank)
		count += ft_putchar(' ');
	if (flags.width)
		count += ft_add_char(nbr, count, &flags, ' ');
	if (nbr >= 0 && flags.plus)
		count += ft_putchar('+');
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (flags.zeros || flags.precision)
		count += ft_add_char(nbr, count, &flags, '0');
	if (flags.precision_is_zero && nbr == 0)
		return (count);
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10, (t_flags){0});
	count += ft_putchar(nbr % 10 + 48);
	return (count);
}

static int	ft_handle_int_min(int nbr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width)
		count = ft_add_char(nbr, 0, &flags, ' ');
	ft_putchar('-');
	if (flags.zeros)
		count += ft_add_char(nbr, 0, &flags, '0');
	if (flags.precision)
		count += ft_add_char(nbr, -1, &flags, '0');
	ft_putstr_fd("2147483648", 1);
	return (11 + count);
}

static int	ft_add_char(int nbr, int len, t_flags *flags, char c)
{
	int	count;
	int	*value;

	count = 0;
	if (c == ' ')
		value = &(flags->width);
	if (c == ' ' && flags->precision >= ft_nbrlen(nbr))
		*value -= flags->precision - ft_nbrlen(nbr);
	if (c == ' ' && flags->precision >= ft_nbrlen(nbr) && nbr < 0)
		(*value)--;
	if (c == '0' && flags->precision)
		value = &(flags->precision);
	else if (c == '0' && flags->zeros)
		value = &(flags->zeros);
	if (c == ' ' && flags->plus && nbr >= 0)
		flags->nbr_len = 1;
	while ((*value > ft_nbrlen_flags(nbr, flags) + len + flags->nbr_len)
		|| (*value == flags->precision
			&& *value > ft_nbrlen(nbr) + flags->nbr_len))
	{
		count += ft_putchar(c);
		(*value)--;
	}
	*value = 0;
	return (count);
}

static int	ft_nbrlen_flags(int nbr, t_flags *flags)
{
	int	len;

	if (nbr == 0 && flags->precision_is_zero)
		return (0);
	if (nbr == -2147483648)
		return (11);
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	if (nbr >= 10)
		len += ft_nbrlen(nbr / 10);
	return (len);
}

int	ft_nbrlen(int nbr)
{
	int	len;

	if (nbr == -2147483648)
		return (11);
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	if (nbr >= 10)
		len += ft_nbrlen(nbr / 10);
	return (len);
}
