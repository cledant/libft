/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:17:46 by cledant           #+#    #+#             */
/*   Updated: 2016/01/19 10:53:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_set_value(t_btree **new, t_btree **node, size_t *flag)
{
	*flag = 1;
	*node = *new;
}

void			ft_btree_add_node(t_btree *root, t_btree *new, int (*cmpf)
					(void *, void *))
{
	t_btree		*node;
	size_t		flag;

	flag = 0;
	node = root;
	while (flag == 0)
	{
		if ((cmpf)(node->content, new->content) > 0)
		{
			if (node->left == NULL)
				ft_set_value(&new, &(node->left), &flag);
			else
				node = node->left;
		}
		else
		{
			if (node->right == NULL)
				ft_set_value(&new, &(node->right), &flag);
			else
				node = node->right;
		}
	}
}
