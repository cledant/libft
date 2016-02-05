/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 12:25:50 by cledant           #+#    #+#             */
/*   Updated: 2016/01/19 11:03:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_apply_postfix(t_btree *root, void (*applyf)(void *))
{
	if (root->left != NULL)
		ft_btree_apply_infix(root->left, applyf);
	if (root->right != NULL)
		ft_btree_apply_infix(root->right, applyf);
	(*applyf)(root->content);
}
