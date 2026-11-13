/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:51:43 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 17:29:12 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	t_list			*cnt;
	unsigned int	i;

	i = 0;
	cnt = lst;
	while (cnt != NULL)
	{
		cnt = cnt->next;
		i++;
	}
	return (i);
}
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	(*new).content = content;
	(*new).next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	(*new).next = *lst;
	*lst = new;
}

int	main(void)
{
	t_list *lst;
	t_list *one;
	t_list *two;
	t_list *three;

	// TEST 1 : Liste vide
	lst = NULL;
	printf("Test 1 - Liste vide : %u\n", ft_lstsize(lst));

	// TEST 2 : Un seul élément
	one = ft_lstnew("Erasmus");
	if (!one)
		return (1);
	printf("Test 2 - Un element : %u\n", ft_lstsize(one));

	// TEST 3 : Trois éléments
	two = ft_lstnew("Julie");
	three = ft_lstnew("Velvet");
	if (!two || !three)
		return (free(one), 1);

	lst = one;
	ft_lstadd_front(&lst, two);
	ft_lstadd_front(&lst, three);

	printf("Test 3 - Trois elements : %u\n", ft_lstsize(lst));

	// TEST 4 : Après un nouvel ajout
	one = ft_lstnew("Thomas");
	if (!one)
		return (1);
	ft_lstadd_front(&lst, one);

	printf("Test 4 - Quatre elements : %u\n", ft_lstsize(lst));

	// Libération de toute la liste
	while (lst)
	{
		one = lst->next;
		free(lst);
		lst = one;
	}

	return (0);
}
*/