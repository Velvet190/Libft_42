/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 18:08:07 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 04:39:00 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoaa(int value, char *str, int base)
{
	long	val;
	long	reste;

	val = value;
	if (val < 0 && base == 10)
	{
		*str = '-';
		str++;
		val = -val;
	}
	if (val >= base)
	{
		str = ft_itoaa(val / base, str, base);
	}
	reste = val % base;
	if (reste > 9)
		*str = (reste - 10) + 'a';
	else
		*str = reste + '0';
	str[1] = '\0';
	return (str + 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	val;
	char	*res;

	val = n;
	len = 0;
	if (val <= 0)
		len++;
	while (val != 0)
	{
		val /= 10;
		len++;
	}
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	ft_itoaa(n, res, 10);
	return (res);
}
/*
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	test(int n, const char *expected, int id)
{
	char	*result;

	result = ft_itoa(n);
	printf("TEST %02d | n = %d | ", id, n);
	if (result && strcmp(result, expected) == 0)
		printf("OK\n");
	else
		printf("FAIL | expected: \"%s\" | got: \"%s\"\n", expected,
			result ? result : "NULL");
	free(result);
}

int	main(void)
{
	test(0, "0", 1);
	test(1, "1", 2);
	test(-1, "-1", 3);
	test(9, "9", 4);
	test(10, "10", 5);
	test(-10, "-10", 6);
	test(99, "99", 7);
	test(-99, "-99", 8);
	test(100, "100", 9);
	test(-100, "-100", 10);
	test(999, "999", 11);
	test(-999, "-999", 12);
	test(1000, "1000", 13);
	test(-1000, "-1000", 14);
	test(12345, "12345", 15);
	test(-12345, "-12345", 16);
	test(100000, "100000", 17);
	test(-100000, "-100000", 18);
	test(1000000000, "1000000000", 19);
	test(-1000000000, "-1000000000", 20);
	test(214748364, "214748364", 21);
	test(-214748364, "-214748364", 22);
	test(INT_MAX, "2147483647", 23);
	test(INT_MIN, "-2147483648", 24);
	test(101010101, "101010101", 25);
	test(-101010101, "-101010101", 26);
	test(111111111, "111111111", 27);
	test(-111111111, "-111111111", 28);
	test(2000000000, "2000000000", 29);
	test(-2000000000, "-2000000000", 30);
	return (0);
}
*/