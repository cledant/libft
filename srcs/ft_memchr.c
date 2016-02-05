/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 20:47:18 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:43:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s++;
		counter++;
	}
	return (NULL);
}
