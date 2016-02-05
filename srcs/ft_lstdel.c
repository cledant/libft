/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:15:31 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:54:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	**ptr_first;
	t_list	*previous_lst;

	ptr_first = alst;
	*ptr_first = *alst;
	while (*alst != NULL)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		previous_lst = *alst;
		*alst = (*alst)->next;
		free(previous_lst);
	}
	free(*ptr_first);
	*ptr_first = NULL;
}
