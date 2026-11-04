/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:33:06 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/04 15:38:34 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char *str, const char *strr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (strr[j])
		j++;
	return (i + j);
}

size_t	ft_strlenmini(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlenmini(dst) >= dstsize)
		return (ft_strlenmini(dst) + dstsize);
	while (i < dstsize)
	{
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && i < dstsize)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(dst, src));
	}
	return (ft_strlen(dst, src));
}
/*
#include <bsd/string.h>
#include <stdio.h>

int	main(void)
{
	char	dst[232111] = "ABC";
	char	src[341111] = "DEF";

	printf("Resultat retour de ft_strlcat : %zu\n", ft_strlcat(dst, src, 1233));
	printf("%s\n", dst);
	printf("Resultat retour de strlcat : %zu\n", strlcat(dst, src, 1233));
	printf("%s\n", dst);
}*/
