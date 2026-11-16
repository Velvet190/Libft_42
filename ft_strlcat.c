/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 11:33:06 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/17 00:31:07 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenn(char *str, const char *strr)
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	tot;

	i = 0;
	j = 0;
	tot = ft_strlen(dst) + ft_strlen(src);
	if (strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (tot);
	while (i < dstsize)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
		while (src[j] != '\0' && i < dstsize)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (tot);
	}
	return (tot);
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
