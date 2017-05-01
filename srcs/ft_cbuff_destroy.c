/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:34:43 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 16:18:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_cbuff_destroy(t_cbuff **cbuff)
{
	free((*cbuff)->buff);
	free((*cbuff)->enqueue_buff);
	free((*cbuff)->dequeue_buff);
	free(*cbuff);
	*cbuff = NULL;
}
