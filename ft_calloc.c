/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:24:21 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/06 16:25:25 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stdlib.h"

#include <string.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

void* ft_calloc(size_t num, size_t size)
{
    void *ptr = malloc(num * size);
    void *res = ft_memset(ptr, 0, size);
    return(res);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

void    *ft_calloc(size_t nmemb, size_t size);

void    test_calloc(size_t nmemb, size_t size)
{
    unsigned char    *mine;
    unsigned char    *real;
    size_t           total;
    size_t           i;
    int              error;

    mine = ft_calloc(nmemb, size);
    real = calloc(nmemb, size);
    total = nmemb * size;
    i = 0;
    error = 0;
    if (!mine || !real)
    {
        printf("Allocation impossible | ft: %p | libc: %p\n",
            (void *)mine, (void *)real);
        free(mine);
        free(real);
        return ;
    }
    while (i < total)
    {
        if (mine[i] != 0 || real[i] != 0)
            error = 1;
        i++;
    }
    printf("calloc(%zu, %zu) | %s\n",
        nmemb, size, error ? "FAIL" : "OK");
    free(mine);
    free(real);
}

int main(void)
{
    test_calloc(0, 0);
    test_calloc(0, 10);
    test_calloc(10, 0);
    test_calloc(1, 1);
    test_calloc(5, 1);
    test_calloc(1, 100);
    test_calloc(10, 10);
    test_calloc(100, 100);
    test_calloc(500, 200);
    test_calloc(1024, 1024);
    test_calloc(SIZE_MAX, 2);
    test_calloc(SIZE_MAX / 2, 4);

    return (0);
}