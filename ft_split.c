/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:18:54 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/19 00:00:46 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntword(char const *str, char c)
{
	int	i;
	int	cnt;
	int	tmp;

	i = 0;
	cnt = 0;
	tmp = 1;
	while (str[i])
	{
		while (str[i] == c)
		{
			tmp = 1;
			i++;
		}
		if (tmp == 1 && str[i] != c && str[i] != '\0')
		{
			cnt++;
			tmp = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (cnt);
}

static void	free_all(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	fill(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			tab[i] = ft_substr(s, 0, len);
			if (!tab[i])
				return (free_all(tab, i), 0);
			i++;
			s += len;
		}
		else
			s++;
	}
	tab[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = ft_cntword(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!fill(result, s, c))
		return (NULL);
	return (result);
}
/*

#include <stdio.h>
#include <stdlib.h>

char			**ft_split(char const *s, char c);

int	main(void)
{
	char	**tab;
	int		i;

	tab = ft_split("  Bonjour   tout  le monde  ", ' ');
	if (!tab)
		return (1);
	i = 0;
	while (tab[i])
	{
		printf("[%d]: '%s'\n", i, tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/