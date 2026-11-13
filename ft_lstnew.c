/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 15:00:01 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 14:38:02 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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