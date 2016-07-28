/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_add_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 14:17:46 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:53:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_set_value(t_btree **new_, t_btree **node, size_t *flag)
{
	*flag = 1;
	*node = *new_;
}

void			ft_btree_add_node(t_btree *root, t_btree *new_, int (*cmpf)
					(void *, void *))
{
	t_btree		*node;
	size_t		flag;

	flag = 0;
	node = root;
	while (flag == 0)
	{
		if ((cmpf)(node->content, new_->content) > 0)
		{
			if (node->left == NULL)
				ft_set_value(&new_, &(node->left), &flag);
			else
				node = node->left;
		}
		else
		{
			if (node->right == NULL)
				ft_set_value(&new_, &(node->right), &flag);
			else
				node = node->right;
		}
	}
}
