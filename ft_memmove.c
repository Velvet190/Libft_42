/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 13:34:07 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/04 10:34:03 by vlaval-a         ###   ########.fr       */
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
		while (i < size)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (destination);
}

/*
int	main(void)
{
	char str[] = "ABCDEFGHIJ";
	ft_memmove(str + 2, str, 8);
	__builtin_printf("%s\n", str);
	return (0);
}
*/