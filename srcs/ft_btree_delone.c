/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:23:04 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 10:01:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_delone(t_btree **alst, void (*del)(void *, size_t))
{
	if (*alst == NULL)
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
}
