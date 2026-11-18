/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:18:54 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/18 16:10:14 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntword(const char *str, char sep)
{
	int	i;
	int	cnt;
	int	tmp;

	i = 0;
	cnt = 0;
	tmp = 1;
	while (str[i])
	{
		while (sep == str[i])
		{
			tmp = 1;
			i++;
		}
		if (tmp == 1 && sep != str[i] && '\0' != str[i])
		{
			cnt++;
			tmp = 0;
		}
		if (str[i] != '\0')
			i++;
	}
	return (cnt);
}

static size_t	ft_strlensp(const char *str, char sep, int old)
{
	size_t	i;

	i = 0;
	while (str[old] == sep)
	{
		old++;
	}
	while (str[old] != sep && str[old] != '\0')
	{
		old++;
		i++;
	}
	return (i);
}

static size_t	ft_strlensp2(const char *str, char sep, int old)
{
	while (str[old] == sep)
	{
		old++;
	}
	while (str[old] != sep && str[old] != '\0')
	{
		old++;
	}
	return (old);
}

static void	ft_strprt(const char *str, char *cas, int len, char sep)
{
	int	i;

	i = 0;
	while (*str == sep)
	{
		str++;
	}
	while (i < len)
	{
		cas[i] = *str;
		i++;
		str++;
	}
	cas[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		old;
	int		ct;
	char	**result;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	old = 0;
	ct = ft_cntword(s, c);
	result = malloc(sizeof(char *) * (ct + 1));
	if(!result)
		return(NULL)
	while (i < ct)
	{
		j = ft_strlensp(s, c, old);
		result[i] = malloc(sizeof(char) * (j + 1));
		ft_strprt(s + old, result[i], j, c);
		old = ft_strlensp2(s, c, old);
		i++;
	}
	result[i] = NULL;
	return (result);
}
/*

#include <stdio.h>
#include <stdlib.h>

char	**ft_split(char const *s, char c);

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