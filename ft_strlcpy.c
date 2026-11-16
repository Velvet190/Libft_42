/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 10:38:10 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/17 00:38:14 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello World";
	char	dest[20] = "";

	printf("Et voila le retour de la taille totale de la chaîne
	qu elle a tenté de créer :
		%zu\n", ft_strlcpy(dest, src, 5));
	printf("Voila la destination : %s\n", dest);
}
*/