/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velvet <velvet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 20:14:54 by velvet            #+#    #+#             */
/*   Updated: 2026/11/13 16:48:35 by velvet           ###   ########.fr       */
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
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Pas de libft.h : on definit tout ici
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Ta fonction (dans ft_lstiter.c)
void				ft_lstiter(t_list *lst, void (*f)(void *));

// Fonctions d'aide du test (noms differents pour ne pas entrer en conflit)
static t_list	*my_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}

static void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	t = *lst;
	while (t->next)
		t = t->next;
	t->next = new;
}

static void	my_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	while (lst && *lst)
	{
		t = (*lst)->next;
		if (del)
			del((*lst)->content);
		free(*lst);
		*lst = t;
	}
}

// ---------- mini framework ----------
static int			g_fail = 0;
static int			g_total = 0;

#define CHECK(cond, msg) do { \

	g_total++; \
	if (cond) printf("  \033[32m[OK]\033[0m %s\n", msg); \
	else { printf("  \033[31m[KO]\033[0m %s  (ligne %d)\n", msg,
		__LINE__); g_fail++; } \
} while (0)

// ---------- fonctions passees a ft_lstiter ----------
static int			g_calls = 0;
static void			*g_seen[200000];

static void	record(void *content)
{
	if (g_calls < 200000)
		g_seen[g_calls] = content;
	g_calls++;
}

static void	increment(void *content)
{
	(*(int *)content)++;
}

static void	upper(void *content)
{
	char	*s;

	s = (char *)content;
	while (*s)
	{
		*s = toupper((unsigned char)*s);
		s++;
	}
}

static void	safe_upper(void *content)
{
	if (content)
		upper(content);
}

static void	f_that_clears_content(void *content)
{
	if (content)
		*(int *)content = 0;
}

static void	reset(void)
{
	g_calls = 0;
	memset(g_seen, 0, sizeof(g_seen));
}

static void	noop(void *content)
{
	(void)content;
}

// ---------- tests ----------

static void	test_null_list(void)
{
	printf("\n[1] Liste NULL\n");
	reset();
	ft_lstiter(NULL, record);
	CHECK(g_calls == 0, "f jamais appelee, pas de crash");
}

static void	test_null_f(void)
{
	t_list	*lst;
	int		a;

	a = 1;
	printf("\n[2] f NULL\n");
	lst = my_lstnew(&a);
	ft_lstiter(lst, NULL);
	CHECK(a == 1, "pas de crash, contenu intact");
	ft_lstiter(NULL, NULL);
	CHECK(1, "liste NULL + f NULL : pas de crash");
	my_lstclear(&lst, noop);
}

static void	test_single(void)
{
	t_list	*lst;
	int		a;

	a = 41;
	printf("\n[3] Un seul element\n");
	reset();
	lst = my_lstnew(&a);
	ft_lstiter(lst, increment);
	CHECK(a == 42, "l'unique element est traite");
	ft_lstiter(lst, record);
	CHECK(g_calls == 1, "f appelee exactement 1 fois");
	my_lstclear(&lst, noop);
}

static void	test_order(void)
{
	t_list	*lst;
	int		v[5] = {0, 1, 2, 3, 4};
	int		i;
	int		ordered;

	printf("\n[4] Ordre de parcours et nombre d'appels\n");
	reset();
	lst = NULL;
	i = 0;
	while (i < 5)
		my_lstadd_back(&lst, my_lstnew(&v[i++]));
	ft_lstiter(lst, record);
	CHECK(g_calls == 5, "f appelee 5 fois (ni plus ni moins)");
	ordered = 1;
	i = 0;
	while (i < 5)
	{
		if (g_seen[i] != &v[i])
			ordered = 0;
		i++;
	}
	CHECK(ordered, "contenus visites dans l'ordre de la liste");
	CHECK(g_seen[0] == &v[0], "premier maillon traite (bug 'avance avant f')");
	CHECK(g_seen[4] == &v[4], "dernier maillon traite");
	my_lstclear(&lst, noop);
}

static void	test_modify_content(void)
{
	t_list	*lst;
	char	s1[] = "hello";
	char	s2[] = "42 lyon";
	char	s3[] = "";

	printf("\n[5] Modification du contenu en place\n");
	lst = my_lstnew(s1);
	my_lstadd_back(&lst, my_lstnew(s2));
	my_lstadd_back(&lst, my_lstnew(s3));
	ft_lstiter(lst, upper);
	CHECK(strcmp(s1, "HELLO") == 0, "s1 en majuscules");
	CHECK(strcmp(s2, "42 LYON") == 0, "s2 en majuscules");
	CHECK(strcmp(s3, "") == 0, "chaine vide inchangee");
	my_lstclear(&lst, noop);
}

static void	test_null_content(void)
{
	t_list	*lst;
	char	s[] = "abc";

	printf("\n[6] Maillons avec content == NULL\n");
	reset();
	lst = my_lstnew(NULL);
	my_lstadd_back(&lst, my_lstnew(s));
	my_lstadd_back(&lst, my_lstnew(NULL));
	ft_lstiter(lst, record);
	CHECK(g_calls == 3, "f appelee pour les 3 maillons, meme avec NULL");
	CHECK(g_seen[0] == NULL && g_seen[1] == s && g_seen[2] == NULL,
		"content NULL bien transmis a f");
	ft_lstiter(lst, safe_upper);
	CHECK(strcmp(s, "ABC") == 0, "pas de crash et maillon du milieu traite");
	my_lstclear(&lst, noop);
}

static void	test_list_intact(void)
{
	t_list	*lst;
	t_list	*n[3];
	int		v[3] = {1, 2, 3};
	int		i;

	printf("\n[7] La structure de la liste n'est pas modifiee\n");
	i = 0;
	while (i < 3)
	{
		n[i] = my_lstnew(&v[i]);
		i++;
	}
	n[0]->next = n[1];
	n[1]->next = n[2];
	lst = n[0];
	ft_lstiter(lst, increment);
	CHECK(lst == n[0], "la tete n'a pas bouge");
	CHECK(n[0]->next == n[1] && n[1]->next == n[2] && n[2]->next == NULL,
		"chainage identique");
	CHECK(n[0]->content == &v[0] && n[1]->content == &v[1]
		&& n[2]->content == &v[2], "pointeurs content identiques");
	CHECK(v[0] == 2 && v[1] == 3 && v[2] == 4, "valeurs incrementees une fois");
	my_lstclear(&lst, noop);
}

static void	test_same_content(void)
{
	t_list	*lst;
	int		a;

	a = 0;
	printf("\n[8] Meme pointeur content dans plusieurs maillons\n");
	lst = my_lstnew(&a);
	my_lstadd_back(&lst, my_lstnew(&a));
	my_lstadd_back(&lst, my_lstnew(&a));
	ft_lstiter(lst, increment);
	CHECK(a == 3, "increment applique 3 fois sur la meme variable");
	ft_lstiter(lst, f_that_clears_content);
	CHECK(a == 0, "f qui remet a 0 fonctionne");
	my_lstclear(&lst, noop);
}

static void	test_big_list(void)
{
	t_list	*lst;
	t_list	*last;
	int		n;
	int		i;
	int		*val;
	int		ok;
	t_list	*node;

	n = 100000;
	printf("\n[9] Grande liste (%d elements)\n", n);
	val = calloc(n, sizeof(int));
	lst = NULL;
	last = NULL;
	i = 0;
	while (i < n)
	{
		node = my_lstnew(&val[i]);
		if (!last)
			lst = node;
		else
			last->next = node;
		last = node;
		i++;
	}
	ft_lstiter(lst, increment);
	ok = 1;
	i = 0;
	while (i < n)
		if (val[i++] != 1)
			ok = 0;
	CHECK(ok, "tous les elements traites exactement une fois");
	reset();
	ft_lstiter(lst, record);
	CHECK(g_calls == n, "nombre d'appels == taille de la liste");
	my_lstclear(&lst, noop);
	free(val);
}

static void	test_twice(void)
{
	t_list	*lst;
	int		a;
	int		b;

	a = 0;
	b = 10;
	printf("\n[10] Appels successifs sur la meme liste\n");
	lst = my_lstnew(&a);
	my_lstadd_back(&lst, my_lstnew(&b));
	ft_lstiter(lst, increment);
	ft_lstiter(lst, increment);
	CHECK(a == 2 && b == 12,
		"la liste est reutilisable apres un premier appel");
	my_lstclear(&lst, noop);
}

int	main(void)
{
	test_null_list();
	test_null_f();
	test_single();
	test_order();
	test_modify_content();
	test_null_content();
	test_list_intact();
	test_same_content();
	test_big_list();
	test_twice();
	printf("\n==== %d/%d tests reussis ====\n", g_total - g_fail, g_total);
	return (g_fail != 0);
}
*/