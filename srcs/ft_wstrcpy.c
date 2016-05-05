/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:47:07 by cledant           #+#    #+#             */
/*   Updated: 2016/05/05 10:32:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrcpy(wchar_t *dst, wchar_t *src)
{
	wchar_t *cpy_dst;

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
