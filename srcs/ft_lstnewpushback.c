/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewpushback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:20:04 by cledant           #+#    #+#             */
/*   Updated: 2016/07/28 21:52:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnewpushback(t_list *new_, void *buff, size_t size)
{
	t_list	*after;

	if (new_ == NULL)
	{
		if ((new_ = ft_lstnew(buff, size)) == NULL)
			return (NULL);
	}
	else
	{
		if ((after = ft_lstnew(buff, size)) == NULL)
		{
			ft_lstdel(&new_, &ft_lstfree_malloc);
			return (NULL);
		}
		ft_lstpushback(new_, after);
	}
	return (new_);
}
