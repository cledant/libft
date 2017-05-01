/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_enqueue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:43:26 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 16:19:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cbuff_enqueue(t_cbuff *cbuff, const size_t e_size)
{
	size_t		first_half;
	size_t		second_half;

	if (e_size > cbuff->size || e_size == 0)
		return (0);
	if ((cbuff->w_pos + e_size - 1) <= (cbuff->size - 1))
		ft_memcpy(cbuff->buff + cbuff->w_pos, cbuff->enqueue_buff, e_size);
	else
	{
		first_half = cbuff->size - cbuff->w_pos;
		second_half = e_size - first_half;
		ft_memcpy(cbuff->buff + cbuff->w_pos, cbuff->enqueue_buff, first_half);
		ft_memcpy(cbuff->buff, cbuff->enqueue_buff + first_half, second_half);
	}
	cbuff->w_pos = (cbuff->w_pos + e_size) % cbuff->size;
	ft_bzero(cbuff->enqueue_buff, cbuff->size + 1);
	if ((cbuff->enqueue_cumul += e_size) > cbuff->size)
		cbuff->overwrite = 1;
	if (cbuff->overwrite == 1)
		cbuff->r_pos = cbuff->w_pos;
	return (e_size);
}
