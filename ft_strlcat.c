/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:19:25 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/18 19:51:30 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	tot;

	i = 0;
	j = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize && dst[i] != '\0')
		i++;
	tot = i + ft_strlen(src);
	if (i == dstsize)
		return (dstsize + ft_strlen(src));
	while (src[j] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
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
