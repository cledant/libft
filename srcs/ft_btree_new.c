/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:12:00 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 10:00:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*ft_btree_new(void const *content, size_t content_size)
{
	t_btree	*new;

	new = (t_btree *)malloc(sizeof(t_btree));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->right = NULL;
		new->left = NULL;
		new->content_size = 0;
		return (new);
	}
	new->content_size = content_size;
	new->content = ft_memalloc(new->content_size);
	if (new->content == NULL)
	{
		free(new);
		return (NULL);
	}
	new->content = ft_memmove(new->content, content, new->content_size);
	new->right = NULL;
	new->left = NULL;
	return (new);
}
