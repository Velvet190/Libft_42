/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 22:01:06 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 00:42:34 by velvet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del || !lst)
		return ;
	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		del(*lst);
		*lst = tmp;
	}
}
/*
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

// Fonction de suppression à passer en paramètre
void	del_content(void *content)
{
	free(content);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i + 1);
}

char	*ft_strdup(const char *s)
{
	size_t			i;
	size_t			j;
	char			*res;
	unsigned char	*n_s;

	n_s = (unsigned char *)s;
	i = ft_strlen(s);
	j = 0;
	res = malloc(i);
	while (j < i)
	{
		res[j] = n_s[j];
		j++;
	}
	res[j + 1] = '\0';
	return (res);
}

int	main(void)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;

	// 1. Création de 3 maillons avec contenu alloué dynamiquement
	head = ft_lstnew(ft_strdup("Maillon 1"));
	node2 = ft_lstnew(ft_strdup("Maillon 2"));
	node3 = ft_lstnew(ft_strdup("Maillon 3"));
	// 2. Chaînage des maillons
	head->next = node2;
	node2->next = node3;
	// 3. Vérification avant suppression
	printf("Avant ft_lstclear : head = %p (%s)\n", (void *)head,
		(char *)head->content);
	// 4. Appel de ta fonction
	ft_lstclear(&head, del_content);
	// 5. Vérification après suppression (doit afficher 0x0 ou (nil))
	printf("Après ft_lstclear : head = %p\n", (void *)head);
	return (0);
}
*/