/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:34:07 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/03 18:11:17 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	i = 0;
	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (d > s)
	{
		while (size)
		{
			d[size] = s[size];
			size--;
		}
	}
	else
	{
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (destination);
}

#include <stdio.h>
#include <string.h>

void test(char *name, int dst, int src, size_t len)
{
    char str1[] = "ABCDEFGHIJ";
    char str2[] = "ABCDEFGHIJ";

    ft_memmove(str1 + dst, str1 + src, len);
    memmove(str2 + dst, str2 + src, len);

    printf("%s\n", name);
    printf("FT  : %s\n", str1);
    printf("LIBC: %s\n", str2);
    printf("TEST: %s\n\n",
        memcmp(str1, str2, sizeof(str1)) == 0 ? "OK" : "FAIL");
}

int main(void)
{
    test("Chevauchement droite", 1, 0, 5);
    test("Chevauchement gauche", 0, 2, 5);
    test("Sans chevauchement", 7, 0, 2);
    test("Copie identique", 0, 0, 5);
    test("Longueur zero", 2, 0, 0);
    test("Copie complete", 0, 0, 10);
    return (0);
}