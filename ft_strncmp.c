/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:55:47 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/04 17:15:31 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i = 0;

    while(s1 && s2 && s1[i] == s2[i] && i < n)
        i++;
    if (s1[i] == '\0' || s2[i] == '\0' || (i == n))
        return(0);
    else if (s1[i] > s2[i])
        return(s1[i] - s2[i]);
    else if (s1[i] < s2[i])
        return(s1[i] - s2[i]);
    return(0);

}
/*
#include <string.h>
#include <stdio.h>

int main(void)
{
    char str1[] = "Je suis moi meme";
    char str2[] = "Je suis p";
    printf("%d\n", ft_strncmp(str1, str2, 0));
    
}
*/