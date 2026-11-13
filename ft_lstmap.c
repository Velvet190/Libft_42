/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 14:34:16 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 17:14:45 by velvet           ###   ########.fr       */
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (first)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

/*

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Fonction 'f' : duplique une chaîne et la passe en majuscules
void	*to_upper_str(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = strdup(str);
	if (!new_str)
		return (NULL);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = toupper(new_str[i]);
		i++;
	}
	return ((void *)new_str);
}

// 2. Fonction 'del' : libère le contenu alloué dynamiquement
void	del_content(void *content)
{
	free(content);
}

// Fonction utilitaire pour afficher la liste
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("[%s] -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*list_src;
	t_list	*list_dest;

	// Création de la liste source avec des chaînes allouées dynamiquement
	list_src = ft_lstnew(strdup("bonjour"));
	ft_lstadd_back(&list_src, ft_lstnew(strdup("l'ecole")));
	ft_lstadd_back(&list_src, ft_lstnew(strdup("42")));
	printf("Liste source : ");
	print_list(list_src);
	// Appel de ft_lstmap
	list_dest = ft_lstmap(list_src, to_upper_str, del_content);
	printf("Liste map    : ");
	print_list(list_dest);
	// Libération de la mémoire des deux listes
	ft_lstclear(&list_src, del_content);
	ft_lstclear(&list_dest, del_content);
	return (0);
}
*/