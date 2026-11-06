/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:18:49 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/06 12:07:02 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		n_c;
	const unsigned char	*n_s;
	size_t				i;

	i = 0;
	n_c = (unsigned char)c;
	n_s = (const unsigned char *)s;
	if (n == i)
		return(NULL);
	while (n_c != n_s[i] && i < n - 1)
		i++;
	if (n_s[i] == n_c)
		return ((void *)&n_s[i]);
	else
		return(NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str1[] = "Bonjour";
	char *ptr1 = ft_memchr(str1, 'r', 7);
	printf("Le resultat de ma fonction est : %s\n", ptr1);
	char str2[] = "Bonjour";
	char *ptr2 = memchr(str2, 'r', 7);
	printf("Le resultat de la vraie fonction est : %s\n", ptr2);
}

void    test_memchr(const char *str, int c, size_t n)
{
    void *mine;
    void *real;

    mine = ft_memchr(str, c, n);
    real = memchr(str, c, n);

    printf("ft_memchr : %p | memchr : %p | %s\n",
        mine, real, mine == real ? "OK" : "FAIL");
}

int main(void)
{
    char str[] = "aabacada";

    test_memchr(str, 'a', 8);
    test_memchr(str, 'b', 8);
    test_memchr(str, 'z', 8);
    test_memchr(str, 'a', 1);
    test_memchr(str, 'a', 0);
    test_memchr(str, '\0', 9);
    test_memchr(str, '\0', 8);
    test_memchr(str, 'd', 8);
    test_memchr(str, 321, 8);
    test_memchr(str, -159, 8);

    return (0);
}
*/