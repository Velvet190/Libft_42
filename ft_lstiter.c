/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:14:54 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 17:13:52 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst || !f)
		return ;
	tmp = lst;
	while (tmp != NULL)
	{
		f((*tmp).content);
		tmp = (*tmp).next;
	}
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	g_total = 0;
static int	g_fail = 0;
static int	g_calls = 0;
static int	g_order = 0;

static void	check(int condition, char *msg, int line)
{
	g_total++;
	if (condition)
		printf("\033[32m[OK]\033[0m %s\n", msg);
	else
	{
		printf("\033[31m[KO]\033[0m %s (ligne %d)\n",
			msg, line);
		g_fail++;
	}
}

static t_list	*new_node(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

static void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

static void	count_calls(void *content)
{
	(void)content;
	g_calls++;
}

static void	increment_value(void *content)
{
	(*(int *)content)++;
}

static void	multiply_value(void *content)
{
	(*(int *)content) *= 2;
}

static void	check_order(void *content)
{
	int	value;

	value = *(int *)content;
	if (value == 10)
		g_order = g_order * 10 + 1;
	else if (value == 20)
		g_order = g_order * 10 + 2;
	else if (value == 30)
		g_order = g_order * 10 + 3;
}

static void	test_empty_list(void)
{
	g_calls = 0;
	ft_lstiter(NULL, count_calls);
	check(g_calls == 0, "Liste NULL : aucun appel", __LINE__);
}

static void	test_single_node(void)
{
	t_list	*lst;
	int		value;

	value = 5;
	lst = new_node(&value);
	if (!lst)
	{
		check(0, "Allocation du noeud", __LINE__);
		return ;
	}
	ft_lstiter(lst, increment_value);
	check(value == 6, "Un element est modifie", __LINE__);
	free_list(&lst);
}

static void	test_multiple_nodes(void)
{
	t_list	*lst;
	t_list	*second;
	t_list	*third;
	int		a;
	int		b;
	int		c;

	a = 1;
	b = 2;
	c = 3;
	lst = new_node(&a);
	second = new_node(&b);
	third = new_node(&c);
	if (!lst || !second || !third)
	{
		check(0, "Allocation des trois noeuds", __LINE__);
		free(lst);
		free(second);
		free(third);
		return ;
	}
	lst->next = second;
	second->next = third;
	ft_lstiter(lst, increment_value);
	check(a == 2 && b == 3 && c == 4,
		"Tous les elements sont modifies", __LINE__);
	free_list(&lst);
}

static void	test_call_count(void)
{
	t_list	*lst;
	t_list	*second;
	t_list	*third;
	int		a;
	int		b;
	int		c;

	a = 10;
	b = 20;
	c = 30;
	lst = new_node(&a);
	second = new_node(&b);
	third = new_node(&c);
	if (!lst || !second || !third)
	{
		check(0, "Allocation des noeuds", __LINE__);
		free(lst);
		free(second);
		free(third);
		return ;
	}
	lst->next = second;
	second->next = third;
	g_calls = 0;
	ft_lstiter(lst, count_calls);
	check(g_calls == 3, "Trois noeuds : trois appels", __LINE__);
	free_list(&lst);
}

static void	test_order(void)
{
	t_list	*lst;
	t_list	*second;
	t_list	*third;
	int		a;
	int		b;
	int		c;

	a = 10;
	b = 20;
	c = 30;
	lst = new_node(&a);
	second = new_node(&b);
	third = new_node(&c);
	if (!lst || !second || !third)
	{
		check(0, "Allocation des noeuds", __LINE__);
		free(lst);
		free(second);
		free(third);
		return ;
	}
	lst->next = second;
	second->next = third;
	g_order = 0;
	ft_lstiter(lst, check_order);
	check(g_order == 123, "Ordre de parcours respecte", __LINE__);
	free_list(&lst);
}

static void	test_second_function(void)
{
	t_list	*lst;
	t_list	*second;
	int		a;
	int		b;

	a = 4;
	b = 7;
	lst = new_node(&a);
	second = new_node(&b);
	if (!lst || !second)
	{
		check(0, "Allocation des noeuds", __LINE__);
		free(lst);
		free(second);
		return ;
	}
	lst->next = second;
	ft_lstiter(lst, multiply_value);
	check(a == 8 && b == 14,
		"Deuxieme callback fonctionne", __LINE__);
	free_list(&lst);
}

int	main(void)
{
	printf("\n===== TESTS FT_LSTITER =====\n\n");
	test_empty_list();
	test_single_node();
	test_multiple_nodes();
	test_call_count();
	test_order();
	test_second_function();
	printf("\nTests : %d | Echecs : %d\n", g_total, g_fail);
	if (g_fail == 0)
		printf("\033[32mTOUS LES TESTS PASSENT\033[0m\n");
	else
		printf("\033[31mDES TESTS ONT ECHOUE\033[0m\n");
	return (g_fail != 0);
}
*/