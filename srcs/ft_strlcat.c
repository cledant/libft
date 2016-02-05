/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:59:11 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:35:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	counter;
	size_t	len_src;

	len_src = ft_strlen(src);
	counter = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*dst != '\0' && counter < size)
	{
		counter++;
		dst++;
	}
	while (*src != '\0')
	{
		if (counter < size - 1)
		{
			*dst = *src;
			dst++;
		}
		src++;
		counter++;
	}
	if (counter == len_src)
		*dst = '\0';
	return (counter);
}
