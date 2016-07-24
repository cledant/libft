/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewpushback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:20:04 by cledant           #+#    #+#             */
/*   Updated: 2016/07/24 20:36:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnewpushback(t_list *new, void *buff, size_t size)
{
	t_list	*after;

	if (new == NULL)
	{
		if ((new = ft_lstnew(buff, size)) == NULL)
			return (NULL);
	}
	else
	{
		if ((after = ft_lstnew(buff, size)) == NULL)
		{
			ft_lstdel(&new, &ft_lstfree_malloc);
			return (NULL);
		}
		ft_lstpushback(new, after);
	}
	return (new);
}
