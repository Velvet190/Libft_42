/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:31:04 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 18:07:42 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cnt;
	t_list	*prev;

	cnt = lst;
	prev = cnt;
	while (cnt != NULL)
	{
		prev = cnt;
		cnt = cnt->next;
	}
	return (prev);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*last;

	last = ft_lstlast(NULL);
	printf("Test 1 (Liste vide) : %p (Attendu : 0x0 ou (nil))\n", (void *)last);
	node1 = malloc(sizeof(t_list));
	node2 = malloc(sizeof(t_list));
	node3 = malloc(sizeof(t_list));
	if (!node1 || !node2 || !node3)
		return (1);
	node1->content = "Premier";
	node1->next = NULL;
	last = ft_lstlast(node1);
	printf("Test 2 (1 element)  : %s (Attendu : Premier)\n",
		(char *)last->content);
	node2->content = "Deuxieme";
	node3->content = "Troisieme";
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	last = ft_lstlast(node1);
	printf("Test 3 (3 elements) : %s (Attendu : Troisieme)\n",
		(char *)last->content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/