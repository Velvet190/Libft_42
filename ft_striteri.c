/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 16:02:58 by velvet            #+#    #+#             */
/*   Updated: 2026/11/10 16:33:04 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int  i = 0;
    if (!s || !f)
        return ;
    while (s[i])
    {
        f(i, s + i);
        i++;
    }
}

#include <stdio.h>

void	toupper_if_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
	{
		*c -= 32; // Convertit en majuscule ASCII
	}
}

int	main(void)
{
	char str[] = "bonjour";

	ft_striteri(str, toupper_if_even);
	printf("%s\n", str); // Affiche "BoNjOuR"
	return (0);
}
