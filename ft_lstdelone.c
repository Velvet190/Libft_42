/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:33:07 by velvet            #+#    #+#             */
/*   Updated: 2026/11/12 19:48:29 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del((*lst).content);
	free(lst);
}

/*
#include <stdio.h>
#include <string.h>

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

// Fonction qui libère le contenu
void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*personne;
	t_list	*personne2;
	char	*texte;
	char	*texte2;

	// TEST 1 : Suppression d'un élément
	texte = malloc(20);
	if (!texte)
		return (1);
	strcpy(texte, "Erasmus");
	personne = ft_lstnew(texte);
	if (!personne)
	{
		free(texte);
		return (1);
	}
	printf("Avant suppression : %s\n", (char *)personne->content);
	ft_lstdelone(personne, del_content);
	printf("Test 1 - Element supprime\n");
	// TEST 2 : Suppression d'un autre élément
	texte2 = malloc(20);
	if (!texte2)
		return (1);
	strcpy(texte2, "Julie");
	personne2 = ft_lstnew(texte2);
	if (!personne2)
	{
		free(texte2);
		return (1);
	}
	printf("Avant suppression : %s\n", (char *)personne2->content);
	ft_lstdelone(personne2, del_content);
	printf("Test 2 - Deuxieme element supprime\n");
	// TEST 3 : Pointeur NULL
	ft_lstdelone(NULL, del_content);
	printf("Test 3 - Pointeur NULL\n");
	return (0);
}
*/