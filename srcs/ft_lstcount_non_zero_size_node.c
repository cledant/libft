/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_non_zero_size_node.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 16:44:57 by cledant           #+#    #+#             */
/*   Updated: 2015/12/15 16:47:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstcount_non_zero_size_node(t_list *list)
{
	size_t	size;

	size = 0;
	while (list != NULL)
	{
		if (list->content_size > 0)
			size++;
		list = list->next;
	}
	return (size);
}
