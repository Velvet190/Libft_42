/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:20:10 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/18 23:12:22 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	realen;

	i = 0;
	realen = ft_strlen(s) - (size_t)start;
	if (len == 0 || start > ft_strlen(s))
	{
		res = malloc(1);
		if (!res)
			return (NULL);
		res[i] = '\0';
		return (res);
	}
	res = malloc(realen + 1);
	if (!res)
		return (NULL);
	while (s[start] && i < len)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

void	test_substr(char const *s, unsigned int start, size_t len)
{
	char	*mine;
	char	*real;
	size_t	max_len;

	mine = ft_substr(s, start, len);
	real = NULL;
	if (start < strlen(s))
	{
		max_len = strlen(s) - start;
		if (len > max_len)
			len = max_len;
	}
	else
		len = 0;
	real = strndup(start <= strlen(s) ? s + start : "", len);
	if (!mine || !real)
	{
		printf("Allocation error | ft: %p | real: %p\n", (void *)mine,
			(void *)real);
	}
	else
	{
		printf("Input: [%s] | start: %u | len: %zu\n", s, start, len);
		printf("ft_substr: [%s] | expected: [%s] | %s\n\n", mine, real,
			strcmp(mine, real) == 0 ? "OK" : "FAIL");
	}
	free(mine);
	free(real);
}

int	main(void)
{
	char	str[] = "bonjour tout le monde";

	test_substr(str, 0, 7);
	test_substr(str, 8, 4);
	test_substr(str, 0, 100);
	test_substr(str, 21, 5);
	test_substr(str, 22, 5);
	test_substr(str, 100, 5);
	test_substr(str, 3, 0);
	test_substr(str, 3, 1);
	test_substr(str, 3, 100);
	test_substr("", 0, 5);
	test_substr("", 10, 5);
	test_substr("a", 0, 1);
	test_substr("a", 1, 1);
	return (0);
}
*/