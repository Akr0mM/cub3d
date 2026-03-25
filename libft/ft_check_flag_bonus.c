/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:18:52 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/10 22:08:22 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_check_zeros(const char *format, int *i, t_flags *flags);
static void	ft_check_left_justify(const char *format, int *i, t_flags *flags);
static void	ft_check_width(const char *format, int *i, t_flags *flags);
static void	ft_check_precision(const char *format, int *i, t_flags *flags);

t_flags	ft_check_flags(const char *format, int *i)
{
	t_flags	flags;

	flags = (t_flags){0};
	(*i)++;
	while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '-'
		|| (format[*i] >= '0' && format[*i] <= '9') || format[*i] == '#'
		|| format[*i] == '.')
	{
		if (format[*i] == ' ' && !flags.plus)
			flags.blank = 1;
		else if (format[*i] == '+')
			ft_check_plus(&flags);
		else if (format[*i] == '#')
			flags.hash = 1;
		else if (format[*i] == '-')
			ft_check_left_justify(format, i, &flags);
		else if (format[*i] == '0' && !flags.left_justify && !flags.precision)
			ft_check_zeros(format, i, &flags);
		else if (format[*i] >= '1' && format[*i] <= '9')
			ft_check_width(format, i, &flags);
		else if (format[*i] == '.')
			ft_check_precision(format, i, &flags);
		(*i)++;
	}
	return (flags);
}

static void	ft_check_precision(const char *format, int *i, t_flags *flags)
{
	int	nb;

	nb = ft_atoi(format + *i + 1);
	if (!nb)
		flags->precision_is_zero = 1;
	if (nb || format[*i + 1] == '0')
		*i += ft_nbrlen(nb);
	flags->precision = nb;
	if (flags->zeros)
		flags->width = flags->zeros;
	flags->zeros = 0;
}

static void	ft_check_width(const char *format, int *i, t_flags *flags)
{
	flags->width = ft_atoi(format + *i);
	*i += ft_nbrlen(flags->width) - 1;
}

static void	ft_check_left_justify(const char *format, int *i, t_flags *flags)
{
	int	j;

	while (format[*i] == '-')
		(*i)++;
	j = ft_atoi(format + *i);
	if (j)
		*i += ft_nbrlen(j) - 1;
	else
		(*i)--;
	flags->left_justify = j;
	flags->zeros = 0;
}

static void	ft_check_zeros(const char *format, int *i, t_flags *flags)
{
	int	j;

	while (format[*i] == '0')
		(*i)++;
	j = ft_atoi(format + *i);
	if (j)
		*i += ft_nbrlen(j) - 1;
	else
		(*i)--;
	flags->zeros = j;
}
