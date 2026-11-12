/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 15:04:58 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 04:37:55 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int	nn;

	nn = (long int)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nn = -nn;
	}
	if (nn > 9)
		ft_putnbr_fd(nn / 10, fd);
	nn = nn % 10 + '0';
	write(fd, &nn, 1);
}
/*
#include "libft.h"
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int	check_file(const char *expected, int fd)
{
	char	buffer[100];
	ssize_t	n;
	size_t	len;

	len = strlen(expected);
	n = read(fd, buffer, sizeof(buffer));
	if (n < 0 || (size_t)n != len)
		return (0);
	return (memcmp(buffer, expected, len) == 0);
}

static void	test(int nbr, int n)
{
	int		fd;
	int		result;
	char	expected[100];

	snprintf(expected, sizeof(expected), "%d", nbr);
	fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	ft_putnbr_fd(nbr, fd);
	lseek(fd, 0, SEEK_SET);
	result = check_file(expected, fd);
	printf("TEST %02d | nbr = %d | %s\n",
		n, nbr, result ? "OK" : "FAIL");
	close(fd);
}

int	main(void)
{
	test(0, 1);
	test(1, 2);
	test(-1, 3);
	test(9, 4);
	test(10, 5);
	test(-10, 6);
	test(42, 7);
	test(-42, 8);
	test(99, 9);
	test(100, 10);
	test(-100, 11);
	test(999, 12);
	test(1000, 13);
	test(-999, 14);
	test(123456789, 15);
	test(-123456789, 16);
	test(INT_MAX, 17);
	test(INT_MIN, 18);
	test(214748364, 19);
	test(-214748364, 20);
	test(1000000000, 21);
	test(-1000000000, 22);
	test(101010101, 23);
	test(-101010101, 24);
	test(111111111, 25);
	test(-111111111, 26);
	test(80808080, 27);
	test(-80808080, 28);
	return (0);
}
*/