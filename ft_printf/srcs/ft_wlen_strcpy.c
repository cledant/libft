/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:47:07 by cledant           #+#    #+#             */
/*   Updated: 2016/04/29 14:14:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wlen_strcpy(wchar_t *dst, wchar_t *src, size_t wlen)
{
	wchar_t *cpy_dst;
	size_t	wlen_total;
	size_t	n_wlen_total;

	wlen_total = 0;
	cpy_dst = dst;
	while (*src != '\0' && wlen_total < wlen)
	{
		wlen_total += ft_wcharlen(*src);
		*dst = *src;
		src++;
		dst++;
		if (*(src + 1) != '\0')
		{
			n_wlen_total = wlen_total + ft_wcharlen(*(src + 1));
			if (n_wlen_total > wlen)
				return (cpy_dst);
		}
	}
	*dst = '\0';
	return (cpy_dst);
}
