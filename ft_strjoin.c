/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:34:33 by velvet            #+#    #+#             */
/*   Updated: 2026/11/09 16:22:08 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	i = 0;
	j = 0;
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	while (j < (ft_strlen(s1) + ft_strlen(s2)) && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (j < (ft_strlen(s1) + ft_strlen(s2)) && s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2);

void	test_strjoin(char const *s1, char const *s2)
{
	char	*mine;
	char	*real;

	mine = ft_strjoin(s1, s2);
	real = malloc(strlen(s1) + strlen(s2) + 1);
	if (!mine || !real)
	{
		printf("Allocation error\n");
		free(mine);
		free(real);
		return ;
	}
	strcpy(real, s1);
	strcat(real, s2);
	printf("s1: [%s] | s2: [%s]\n", s1, s2);
	printf("ft_strjoin: [%s] | expected: [%s] | %s\n\n",
		mine, real, strcmp(mine, real) == 0 ? "OK" : "FAIL");
	free(mine);
	free(real);
}

int	main(void)
{
	test_strjoin("bonjour", " monde");
	test_strjoin("", "bonjour");
	test_strjoin("bonjour", "");
	test_strjoin("", "");
	test_strjoin("a", "b");
	test_strjoin("123456789", "987654321");
	test_strjoin("   ", "   ");
	test_strjoin("hello", "\nworld");
	test_strjoin("abc", "abc");
	test_strjoin("une phrase ", "assez longue pour tester");
	test_strjoin("fin", "");
	return (0);
}
*/