/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:07:30 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/04 16:33:06 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c)
		i++;
	return ((char *)str + i);
}
/*
int	main(void)
{
	char	str[] = "Je suis moi meme et pas celui qui evolue dans le paraitre.";

	ft_strchr(str, 'o');
	__builtin_printf("%s\n", ft_strchr(str, 'c'));
}
*/