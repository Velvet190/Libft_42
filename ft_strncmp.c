/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:19:48 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/18 03:29:05 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*n_s1;
	unsigned char	*n_s2;

	n_s1 = (unsigned char *)s1;
	n_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && n_s1[i] && n_s2[i] && n_s1[i] == n_s2[i])
		i++;
	if (i == n)
		return (0);
	else if (n_s1[i] > n_s2[i])
		return (n_s1[i] - n_s2[i]);
	else if (n_s1[i] < n_s2[i])
		return (n_s1[i] - n_s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Je suis moi meme";
	char	str2[] = "Je suis p";

	printf("%d\n", ft_strncmp(str1, str2, 0));
}
*/