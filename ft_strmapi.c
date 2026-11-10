/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:38:11 by velvet            #+#    #+#             */
/*   Updated: 2026/11/10 18:06:49 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		i++;
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	while (j != i)
	{
		res[j] = f(j, s[j]);
		j++;
	}
	res[j] = '\0';
	return (res);
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

char identity(unsigned int i, char c)
{
    (void)i;
    return (c);
}

char uppercase(unsigned int i, char c)
{
    (void)i;
    return ((char)toupper((unsigned char)c));
}

char lowercase(unsigned int i, char c)
{
    (void)i;
    return ((char)tolower((unsigned char)c));
}

char index_char(unsigned int i, char c)
{
    (void)c;
    return ((char)('0' + i % 10));
}

char alternate(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ((char)toupper((unsigned char)c));
    return ((char)tolower((unsigned char)c));
}

char reverse_alpha(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return ('z' - (c - 'a'));
    return (c);
}

char shift_char(unsigned int i, char c)
{
    (void)i;
    return (c + 1);
}

static void test(const char *input,
    char (*f)(unsigned int, char), const char *expected, int n)
{
    char *result;

    result = ft_strmapi(input, f);
    printf("TEST %02d : ", n);
    if (result && strcmp(result, expected) == 0)
        printf("OK\n");
    else
        printf("FAIL | expected: \"%s\" | got: \"%s\"\n",
            expected, result ? result : "NULL");
    free(result);
}

int main(void)
{
    test("", identity, "", 1);
    test("hello", identity, "hello", 2);
    test("hello", uppercase, "HELLO", 3);
    test("HELLO", lowercase, "hello", 4);
    test("abcdef", index_char, "012345", 5);
    test("abcdef", alternate, "AbCdEf", 6);
    test("azby", reverse_alpha, "zayb", 7);
    test("12345", shift_char, "23456", 8);
    test("a b c", uppercase, "A B C", 9);
    test("42 School", identity, "42 School", 10);
    test("abcdefghijklm", index_char, "0123456789012", 11);
    test("AaZz", alternate, "AaZz", 12);
    test("00000", shift_char, "11111", 13);
    test("!!!", identity, "!!!", 14);
    test("a", index_char, "0", 15);
    test("z", reverse_alpha, "a", 16);
    test("AZaz09", lowercase, "azaz09", 17);
    test("0123456789", index_char, "0123456789", 18);

    return (0);
}
*/