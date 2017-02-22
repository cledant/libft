/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_precision_str_simple.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:35:00 by cledant           #+#    #+#             */
/*   Updated: 2016/04/29 13:34:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_printf_mod_precision_str_w(wchar_t *s, size_t pre_size)
{
	size_t	s_len;
	size_t	r_len;
	wchar_t	*new;

	if ((s_len = ft_wstrlen(s)) <= pre_size)
		return (s);
	r_len = ft_wlen_strnlen(s, pre_size);
	if ((new = ft_wstrnew(r_len)) == NULL)
		return (NULL);
	new = ft_wlen_strcpy(new, s, pre_size);
	free(s);
	return (new);
}
