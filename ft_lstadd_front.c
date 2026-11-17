/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaval-a <vlaval-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 18:16:57 by vlaval-a          #+#    #+#             */
/*   Updated: 2026/11/17 18:21:16 by vlaval-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	(*new).next = *lst;
	*lst = new;
}

/*

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

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*lst;
	t_list	*new1;
	t_list	*new2;

	lst = ft_lstnew("Erasmus");
	new1 = ft_lstnew("Julie");
	new2 = ft_lstnew("vlaval-a");
	if (!lst || !new1 || !new2)
		return (1);
	ft_lstadd_front(&lst, new1);
	ft_lstadd_front(&lst, new2);
	while (lst)
	{
		printf("Content : %s\n", (char *)lst->content);
		lst = lst->next;
	}
	return (0);
}
*/