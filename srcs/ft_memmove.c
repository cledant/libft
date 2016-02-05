/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:18:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:42:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	counter;
	void	*cpy_dst;
	char	temp[len];

	counter = 0;
	cpy_dst = dst;
	while (counter < len)
	{
		temp[counter] = *(char *)src;
		src++;
		counter++;
	}
	counter = 0;
	while (counter < len)
	{
		*(char *)dst = temp[counter];
		dst++;
		counter++;
	}
	return (cpy_dst);
}
