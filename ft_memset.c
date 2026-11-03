/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:42:59 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/03 16:03:21 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
/*
#include <stdio.h>

int	main(void)
{
	char	array[] = "Salut";

	ft_memset(array, 'f', 2);
	printf("%s\n", array);
}
*/