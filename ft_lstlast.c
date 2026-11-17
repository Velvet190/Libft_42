/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:17:20 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/17 18:55:45 by vlaval-a         ###   ########.fr       */
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