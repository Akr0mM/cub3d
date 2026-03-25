/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfaivre <mfaivre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:49:08 by mfaivre           #+#    #+#             */
/*   Updated: 2025/12/12 01:22:33 by mfaivre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			n++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (n);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*str;
	int		i;

	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static int	free_all_s(char **tab, int k)
{
	while (k >= 0)
		free(tab[k--]);
	free(tab);
	return (0);
}

static int	fill_tab(char **tab, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		if (j > i)
		{
			tab[k] = word_dup(s, i, j);
			if (!tab[k])
				return (free_all_s(tab, k - 1));
			k++;
		}
		i = j;
	}
	tab[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wc;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	tab = malloc((wc + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	if (!fill_tab(tab, s, c))
		return (NULL);
	return (tab);
}

/*
#include <stdio.h>
int	main()
{
	char *s = "      a   ed fa   asd sk   ";
	char **tab = ft_split(s, ' ');
	int i = 0;

	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
*/