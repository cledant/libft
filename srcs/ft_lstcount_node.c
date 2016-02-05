/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:44:57 by cledant           #+#    #+#             */
/*   Updated: 2015/12/20 12:39:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcount_node(t_list *list)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		size++;
		list = list->next;
	}
	return (size);
}
