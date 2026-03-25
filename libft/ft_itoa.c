/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:00:10 by mfaivre           #+#    #+#             */
/*   Updated: 2025/11/12 12:06:59 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	nb_get_size(int n, size_t *size)
{
	if (n == -2147483648)
	{
		*size = 11;
		return ;
	}
	if (n < 0)
	{
		(*size)++;
		n *= -1;
	}
	if (n >= 10)
		nb_get_size(n / 10, size);
	(*size)++;
}

static char	*ft_int_min_string(void)
{
	char	*string;

	string = malloc(12 * sizeof(char));
	if (!string)
		return (NULL);
	string[0] = '-';
	string[1] = '2';
	string[2] = '1';
	string[3] = '4';
	string[4] = '7';
	string[5] = '4';
	string[6] = '8';
	string[7] = '3';
	string[8] = '6';
	string[9] = '4';
	string[10] = '8';
	string[11] = '\0';
	return (string);
}

char	*ft_itoa(int n)
{
	int		i;
	size_t	nb_size;
	char	*nb;

	if (n == -2147483648)
		return (ft_int_min_string());
	nb_size = 0;
	nb_get_size(n, &nb_size);
	nb = malloc((nb_size + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	else if (n < 0)
	{
		n *= -1;
		nb[0] = '-';
	}
	i = nb_size - 1;
	while (n >= 10)
	{
		nb[i--] = n % 10 + 48;
		n /= 10;
	}
	nb[i] = n + 48;
	nb[nb_size] = '\0';
	return (nb);
}

/*
#include <stdio.h>
int	main()
{
	printf("%s\n", ft_itoa(-2147483648));
}
*/