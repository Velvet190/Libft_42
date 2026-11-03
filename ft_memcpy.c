/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:34:07 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/03 16:27:23 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*b;
	size_t			i;

	i = 0;
	p = (unsigned char *)dest;
	b = (unsigned char *)src;
	while (i < n)
	{
		p[i] = b[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char src[] = "Salut";
	char dest[100];
	ft_memcpy(dest, src, 5);
	printf("%s", dest);
}
*/