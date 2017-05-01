/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_dequeue_till_head_no_change.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 16:26:07 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 16:26:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t		get_max_dequeue_size(t_cbuff *cbuff)
{
	size_t		max_d_size;

	if (cbuff->r_pos < cbuff->w_pos)
		max_d_size = cbuff->w_pos - cbuff->r_pos;
	else if (cbuff->r_pos > cbuff->w_pos)
		max_d_size = cbuff->size - cbuff->r_pos + cbuff->w_pos;
	else if (cbuff->r_pos == cbuff->w_pos && cbuff->enqueue_cumul == 0 &&
			cbuff->overwrite == 0)
		max_d_size = 0;
	else
		max_d_size = cbuff->size;
	return (max_d_size);
}

static inline void			cpy_not_contigous(t_cbuff *cbuff, const size_t size)
{
	size_t		first_half;
	size_t		second_half;

	if ((cbuff->r_pos + size - 1) <= (cbuff->size - 1))
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, size);
	else
	{
		first_half = cbuff->size - cbuff->r_pos;
		second_half = cbuff->w_pos;
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, first_half);
		ft_memcpy(cbuff->dequeue_buff + first_half, cbuff->buff, second_half);
	}
}

size_t						ft_cbuff_dequeue_till_head_no_change(t_cbuff *cbuff)
{
	size_t		max_d_size;

	ft_bzero(cbuff->dequeue_buff, cbuff->size + 1);
	if ((max_d_size = get_max_dequeue_size(cbuff)) == 0)
		return (0);
	if (cbuff->w_pos > cbuff->r_pos)
		ft_memcpy(cbuff->dequeue_buff, cbuff->buff + cbuff->r_pos, max_d_size);
	else
		cpy_not_contigous(cbuff, max_d_size);
	return (max_d_size);
}
