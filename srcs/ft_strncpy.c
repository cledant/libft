/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:18:09 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:35:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*cpy_dst;
	size_t	counter;

	counter = 0;
	cpy_dst = dst;
	while (counter < n)
	{
		*dst = *src;
		if (*src != '\0')
			src++;
		dst++;
		counter++;
	}
	return (cpy_dst);
}
