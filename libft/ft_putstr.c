/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:57:02 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:09:12 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_add_char_string(char *s, t_flags *flags, char c);
static int	ft_strlen_flags(char *s, t_flags *flags);

int	ft_putstr(char *s, t_flags *flags)
{
	int	count;
	int	space;

	space = 0;
	if (!s)
	{
		flags->is_null = 1;
		return (ft_putstr("(null)", flags));
	}
	if (flags->width)
		space = ft_add_char_string(s, flags, ' ');
	if (flags->zeros)
		space = ft_add_char_string(s, flags, '0');
	count = 0;
	if (flags->is_null && (flags->precision && flags->precision < 6))
		return (space);
	while (s[count] && ((!flags->precision && !flags->precision_is_zero)
			|| count < flags->precision))
	{
		ft_putchar(s[count]);
		count++;
	}
	return (count + space);
}

static int	ft_add_char_string(char *s, t_flags *flags, char c)
{
	int	count;
	int	str_len;
	int	*value;

	count = 0;
	str_len = ft_strlen_flags(s, flags);
	if (c == '0')
		value = &(flags->zeros);
	if (c == ' ')
		value = &(flags->width);
	while (*value > str_len)
	{
		count += ft_putchar(c);
		(*value)--;
	}
	*value = 0;
	return (count);
}

static int	ft_strlen_flags(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if ((flags->precision && flags->precision < i) || flags->precision_is_zero)
		return (flags->precision);
	return (i);
}
