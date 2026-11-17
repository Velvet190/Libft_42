/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:17:29 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/17 18:55:52 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*texte;
	t_list	*personne;

	texte = "Erasmus";
	personne = ft_lstnew(texte);
	if (!personne)
		return (1);
	printf("Content : [%s]\n", (char *)personne->content);
	printf("Next : [%p]\n", (void *)personne->next);
	free(personne);
	return (0);
}
*/