/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:34:07 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/09 14:22:19 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)destination;
	s = (unsigned char *)source;
	if (destination == source || size == 0)
		return (destination);
	if (d > s && d < s + size)
	{
		while (size > 0)
		{
			size--;
			d[size] = s[size];
		}
	}
	else
	{
		while (size-- > 0)
			*d++ = *s++;
	}
	return (destination);
}
/*
int	main(void)
{
	char	str[] = "ABCDEFGHIJ";

	ft_memmove(str + 2, str, 10);
	__builtin_printf("%s\n", str);
	return (0);
}
*/