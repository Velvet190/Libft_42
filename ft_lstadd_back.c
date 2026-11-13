/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 18:16:55 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 16:44:10 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	if (!new || !lst)
		return ;
	while ((*tmp).next != NULL)
	{
		tmp = (*tmp).next;
	}
	(*tmp).next = new;
}
/*
#include <stdlib.h>

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

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new;
	t_list	*current;

	// TEST 1 : Liste vide
	lst = NULL;
	new = ft_lstnew("Erasmus");
	if (!new)
		return (1);
	ft_lstadd_back(&lst, new);
	printf("Test 1 - Liste vide : %u element(s)\n", ft_lstsize(lst));
	// TEST 2 : Ajout à la fin
	new = ft_lstnew("Julie");
	if (!new)
		return (1);
	ft_lstadd_back(&lst, new);
	printf("Test 2 - Deux elements : %u element(s)\n", ft_lstsize(lst));
	// TEST 3 : Plusieurs ajouts
	new = ft_lstnew("Velvet");
	if (!new)
		return (1);
	ft_lstadd_back(&lst, new);
	new = ft_lstnew("Thomas");
	if (!new)
		return (1);
	ft_lstadd_back(&lst, new);
	printf("Test 3 - Quatre elements : %u element(s)\n", ft_lstsize(lst));
	// Affichage de la liste
	current = lst;
	printf("\nContenu de la liste :\n");
	while (current != NULL)
	{
		printf("- %s\n", (char *)current->content);
		current = current->next;
	}
	// Libération
	while (lst != NULL)
	{
		current = lst->next;
		free(lst);
		lst = current;
	}
	return (0);
}
*/