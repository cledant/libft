/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:18:24 by cledant           #+#    #+#             */
/*   Updated: 2017/05/01 16:19:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_cbuff			*clean_fail(void *base, void *buff_1,
							void *buff_2, void *buff_3)
{
	if (buff_1 != NULL)
		free(buff_1);
	if (buff_2 != NULL)
		free(buff_2);
	if (buff_3 != NULL)
		free(buff_3);
	if (base != NULL)
		free(base);
	return (NULL);
}

static inline void		init_buffers(t_cbuff *new_buffer,
							const size_t buff_size)
{
	ft_bzero(new_buffer->buff, buff_size + 1);
	ft_bzero(new_buffer->enqueue_buff, buff_size + 1);
	ft_bzero(new_buffer->dequeue_buff, buff_size + 1);
	new_buffer->r_pos = 0;
	new_buffer->w_pos = 0;
	new_buffer->overwrite = 0;
	new_buffer->size = buff_size;
	new_buffer->enqueue_cumul = 0;
}

t_cbuff					*ft_cbuff_create(const size_t buff_size)
{
	t_cbuff		*new_cbuff;

	if (buff_size == 0)
		return (NULL);
	if ((new_cbuff = (t_cbuff *)malloc(sizeof(t_cbuff))) == NULL)
		return (NULL);
	if ((new_cbuff->buff = (char *)malloc(sizeof(char) * (buff_size + 1)))
			== NULL)
		return (clean_fail(new_cbuff, new_cbuff->buff, NULL, NULL));
	if ((new_cbuff->enqueue_buff = (char *)malloc(sizeof(char) *
			(buff_size + 1))) == NULL)
	{
		return (clean_fail(new_cbuff, new_cbuff->buff, new_cbuff->enqueue_buff,
			NULL));
	}
	if ((new_cbuff->dequeue_buff = (char *)malloc(sizeof(char) *
			(buff_size + 1))) == NULL)
	{
		return (clean_fail(new_cbuff, new_cbuff->buff, new_cbuff->enqueue_buff,
			new_cbuff->dequeue_buff));
	}
	init_buffers(new_cbuff, buff_size);
	return (new_cbuff);
}
