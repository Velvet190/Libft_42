/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:07:36 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/09 14:22:35 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lil;
	size_t	cnt;

	cnt = 0;
	lil = (size_t)ft_strlen(little);
	i = 0;
	if (lil == 0)
		return ((char *)big);
	while (big && i < len && big[i])
	{
		while (big[i + cnt] == little[cnt] && i + cnt < len && big[i + cnt])
		{
			cnt++;
			if (cnt == lil)
				return ((char *)&big[i]);
		}
		i++;
		cnt = 0;
	}
	return (NULL);
}
/*
#include <bsd/string.h>
#include <stdio.h>

void	test_strnstr(const char *big, const char *little, size_t len)
{
	char	*mine;
	char	*real;

	mine = ft_strnstr(big, little, len);
	real = strnstr(big, little, len);
	printf("ft_strnstr : %p | strnstr : %p | %s\n", (void *)mine, (void *)real,
		mine == real ? "OK" : "FAIL");
}

int	main(void)
{
	char	big[] = "bonjour je suis un test";
	char	big2[] = "aaaaaaa";
	char	big3[] = "abc";
	char	big4[] = "abcdefgh";
	char	big5[] = "hello";

	test_strnstr(big, "bonjour", 23);
	test_strnstr(big, "je suis", 23);
	test_strnstr(big, "test", 23);
	test_strnstr(big, "inexistant", 23);
	test_strnstr(big, "bonjour", 0);
	test_strnstr(big, "", 0);
	test_strnstr(big, "", 23);
	test_strnstr(big, "test", 22);
	test_strnstr(big2, "aaa", 7);
	test_strnstr(big2, "aaaaaaa", 7);
	test_strnstr(big2, "aaaaaaaa", 7);
	test_strnstr(big3, "bc", 3);
	test_strnstr(big3, "bc", 2);
	test_strnstr(big3, "abc", 3);
	test_strnstr(big4, "def", 6);
	test_strnstr(big4, "def", 5);
	test_strnstr(big4, "fgh", 8);
	test_strnstr(big5, "lo", 5);
	test_strnstr(big5, "llo", 4);
	return (0);
}
*/