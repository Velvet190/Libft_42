/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:59:25 by velvet            #+#    #+#             */
/*   Updated: 2026/11/10 14:11:48 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
/*

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int check_file(const char *expected, int fd)
{
    char buffer[4096];
    ssize_t n;
    size_t len;

    len = strlen(expected);
    n = read(fd, buffer, sizeof(buffer));
    if (n < 0 || (size_t)n != len)
        return (0);
    return (memcmp(buffer, expected, len) == 0);
}

static void test(char *str, const char *expected, int n)
{
    int fd;
    int result;

    fd = open("test_output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return ;
    ft_putstr_fd(str, fd);
    lseek(fd, 0, SEEK_SET);
    result = check_file(expected, fd);
    printf("TEST %02d : %s\n", n, result ? "OK" : "FAIL");
    close(fd);
}

int main(void)
{
    test("Hello", "Hello", 1);
    test("", "", 2);
    test("42", "42", 3);
    test("Hello World!", "Hello World!", 4);
    test("     ", "     ", 5);
    test("\n", "\n", 6);
    test("\t", "\t", 7);
    test("\n\t\r", "\n\t\r", 8);
    test("a\nb\nc", "a\nb\nc", 9);
    test("1234567890", "1234567890", 10);
    test("Special: !@#$%^&*()", "Special: !@#$%^&*()", 11);
    test("Un texte assez long pour tester une chaine plus grande.",
        "Un texte assez long pour tester une chaine plus grande.", 12);
    test("End", "End", 13);
    test("42 School", "42 School", 14);
    test("a", "a", 15);

    ft_putstr_fd("STDOUT TEST\n", 1);
    ft_putstr_fd("STDERR TEST\n", 2);

    return (0);
}
*/