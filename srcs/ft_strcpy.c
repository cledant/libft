/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:47:07 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:34:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char *cpy_dst;

	cpy_dst = dst;
	while (*src != '\0')
	{
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return (cpy_dst);
}
