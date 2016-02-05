/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:45:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:55:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_internal_map(t_list *lst, t_list *(*f)(t_list *elem),
								t_list *p_new)
{
	t_list	*new;
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = (*f)(lst);
		new = ft_lstnew(NULL, 0);
		if (new == NULL)
			return (0);
		p_new->next = new;
		new->content_size = tmp->content_size;
		new->content = ft_memalloc(new->content_size);
		if (new->content == NULL)
			return (0);
		new->content = tmp->content;
		p_new = new;
		lst = lst->next;
	}
	return (1);
}

static void		*ft_clean(t_list **first)
{
	ft_lstdel(first, &ft_bzero);
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*first;
	t_list	*prev_new;

	if (lst == NULL)
		return (lst);
	tmp = (*f)(lst);
	new = ft_lstnew(NULL, 0);
	if (new == NULL)
		return (new);
	first = new;
	new->content_size = tmp->content_size;
	new->content = ft_memalloc(new->content_size);
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	new->content = tmp->content;
	prev_new = new;
	lst = lst->next;
	if (ft_internal_map(lst, f, prev_new) == 0)
		return (ft_clean(&first));
	return (first);
}
