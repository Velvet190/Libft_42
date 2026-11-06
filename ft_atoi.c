/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 14:48:45 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/06 15:19:53 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int i = 0;
	int res = 0;
    int neg = 1;
	while (str[i] <= ' ')
		i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            neg = -neg;
        }
        i++;
    } 
	while (str[i] >= '0' && str[i] <= '9')
    {
		res = res * 10 + (str[i] - 48);
        i++;
    }
	return (res*neg);
}
/*
#include <stdio.h>
#include <stdlib.h>


void    test_atoi(const char *str)
{
    int mine;
    int real;

    mine = ft_atoi(str);
    real = atoi(str);

    printf("Input: [%s]\n", str);
    printf("ft_atoi: %d | atoi: %d | %s\n\n",
        mine, real, mine == real ? "OK" : "FAIL");
}

int main(void)
{
    test_atoi("42");
    test_atoi("-42");
    test_atoi("+42");
    test_atoi("0");
    test_atoi("00042");

    test_atoi("   42");
    test_atoi("\t\n\v\f\r 42");
    test_atoi("   -42");
    test_atoi("   +42");

    test_atoi("42abc");
    test_atoi("abc42");
    test_atoi("42 56");
    test_atoi("");

    test_atoi("--42");
    test_atoi("+-42");
    test_atoi("++42");
    test_atoi("-+42");

    test_atoi("2147483647");
    test_atoi("-2147483648");

    return (0);
}
*/