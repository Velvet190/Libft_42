/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:26:49 by velvet            #+#    #+#             */
/*   Updated: 2026/11/09 16:22:37 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(const char *s)
{
	size_t			i;
	size_t			j;
	char			*res;
	unsigned char	*n_s;

	n_s = (unsigned char *)s;
	i = ft_strlen(s);
	j = 0;
	res = malloc(i);
	while (j < i)
	{
		res[j] = n_s[j];
		j++;
	}
	res[j + 1] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s);

void	test_strdup(const char *s)
{
	char	*mine;
	char	*real;

	mine = ft_strdup(s);
	real = strdup(s);
	if (!mine || !real)
	{
		printf("Allocation error\n");
		free(mine);
		free(real);
		return ;
	}
	printf("Input: [%s]\n", s);
	printf("ft_strdup: [%s] | strdup: [%s] | %s\n\n", mine, real, strcmp(mine,
			real) == 0 ? "OK" : "FAIL");
	if (mine == real)
		printf("ERROR: same address!\n");
	free(mine);
	free(real);
}

int	main(void)
{
	test_strdup("bonjour");
	test_strdup("");
	test_strdup("a");
	test_strdup("42");
	test_strdup("Une phrase beaucoup plus longue");
	test_strdup("     espaces     ");
	test_strdup("1234567890");
	test_strdup("!@#$%^&*()_+-=");
	test_strdup("\t\n\r");
	test_strdup("a\0b");

	return (0);
}
 */