/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:43:15 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/09 14:22:16 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*n_s1;
	unsigned char	*n_s2;
	size_t			i;

	i = 0;
	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	while (n_s1[i] == n_s2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else if (n_s1[i] > n_s2[i])
		return (n_s1[i] - n_s2[i]);
	else if (n_s1[i] < n_s2[i])
		return (n_s1[i] - n_s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	int	mine;
	int	real;

	mine = ft_memcmp(s1, s2, n);
	real = memcmp(s1, s2, n);
	printf("ft_memcmp : %d | memcmp : %d | %s\n", mine, real, (mine == 0
			&& real == 0) || (mine < 0 && real < 0) || (mine > 0
			&& real > 0) ? "OK" : "FAIL");
}

int	main(void)
{
	char			s1[] = "bonjour";
	char			s2[] = "bonjour";
	char			s3[] = "bonsoir";
	char			s4[] = "bonjoux";
	unsigned char	s5[] = {0x80, 0xFF, 0x00};
	unsigned char	s6[] = {0x7F, 0xFF, 0x00};

	test_memcmp(s1, s2, 7);
	test_memcmp(s1, s3, 7);
	test_memcmp(s1, s4, 7);
	test_memcmp(s1, s3, 3);
	test_memcmp(s1, s3, 0);
	test_memcmp(s1, s2, 0);
	test_memcmp(s1, s3, 7);
	test_memcmp(s1, s3, 1);
	test_memcmp(s5, s6, 3);
	test_memcmp(s5, s6, 0);
	return (0);
}
*/