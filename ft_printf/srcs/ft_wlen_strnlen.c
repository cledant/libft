/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wlen_strnlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 13:06:19 by cledant           #+#    #+#             */
/*   Updated: 2016/04/29 14:06:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wlen_strnlen(wchar_t *s, size_t wlen)
{
	size_t	length;
	size_t	wtotal_len;

	length = 0;
	wtotal_len = 0;
	while (*s != '\0' && wtotal_len < wlen)
	{
		wtotal_len += ft_wcharlen(*s);
		length++;
		s++;
	}
	return (length);
}
