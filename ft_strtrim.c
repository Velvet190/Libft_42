/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 16:23:31 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 04:40:25 by velvet           ###   ########.fr       */
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

size_t	ft_verif(char c1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	j;
	size_t	end;
	size_t	dbt;

	dbt = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (dbt < end && ft_verif(s1[dbt], set))
		dbt++;
	while (end > dbt && ft_verif(s1[end - 1], set))
		end--;
	res = malloc(end - dbt + 1);
	if (!res)
		return (NULL);
	while (dbt < end)
	{
		res[j] = s1[dbt];
		dbt++;
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

static char	*reference_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*res;

	start = 0;
	end = strlen(s1);
	while (s1[start] && strchr(set, s1[start]))
		start++;
	while (end > start && strchr(set, s1[end - 1]))
		end--;
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}

static void	test(const char *s1, const char *set, int n)
{
	char	*expected;
	char	*result;

	expected = reference_strtrim(s1, set);
	result = ft_strtrim(s1, set);
	printf("\nTEST %02d: s1=\"%s\" | set=\"%s\"\n", n, s1, set);
	printf("Expected : \"%s\"\n", expected ? expected : "NULL");
	printf("Your ft  : \"%s\"\n", result ? result : "NULL");
	if (!expected || !result)
		printf("RESULT   : %s\n", expected == result ? "OK" : "FAIL");
	else
		printf("RESULT   : %s\n", strcmp(expected,
				result) == 0 ? "OK" : "FAIL");
	free(expected);
	free(result);
}

int	main(void)
{
	test("...bonjour...", ".", 1);
	test("xx42xx", "x", 2);
	test("", "abc", 3);
	test("bonjour", "", 4);
	test("aaaaa", "a", 5);
	test("ababab", "ab", 6);
	test("abc", "abc", 7);
	test("  hello  ", " ", 8);
	test("\t\nhello\n\t", " \t\n", 9);
	test("xxhelloxxworldxx", "x", 10);
	test("aabbcc", "ab", 11);
	test("ccbaabc", "abc", 12);
	test("123456789", "123", 13);
	test("!!!hello???", "!?", 14);
	test("hello", "h", 15);
	test("hello", "o", 16);
	test("hello", "ho", 17);
	test("  ", " ", 18);
	test("ababhelloabab", "ab", 19);
	test("mississippi", "im", 20);
	test(" \t\n ", " \t\n", 21);
	test("a", "a", 22);
	test("a", "b", 23);
	test("   abc   ", " abc", 24);
	test("abcabcabc", "ac", 25);
	return (0);
}
*/