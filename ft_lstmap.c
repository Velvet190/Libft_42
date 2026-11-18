/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:17:25 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/18 20:00:09 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*content;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			ft_lstclear(&first, del);
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