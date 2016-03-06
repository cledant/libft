/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 10:07:24 by cledant           #+#    #+#             */
/*   Updated: 2016/03/06 20:58:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree_malloc(void *content, size_t size)
{
	size++;
	if (content != NULL)
	{
		free(content);
		content = NULL;
	}
}
