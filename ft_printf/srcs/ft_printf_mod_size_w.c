/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:26:33 by cledant           #+#    #+#             */
/*   Updated: 2016/04/29 13:52:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_printf_mod_size_w(wchar_t *s, size_t size_len)
{
	size_t		s_len;
	wchar_t		*new;
	wchar_t		*cpy_new;
	size_t		i;

	if ((s_len = ft_wstrlen(s)) >= size_len)
		return (s);
	i = 0;
	if ((new = ft_wstrnew(size_len)) == NULL)
		return (NULL);
	cpy_new = new;
	while (i < (size_len - s_len))
	{
		*new = ' ';
		new++;
		i++;
	}
	ft_wstrcpy(new, s);
	free(s);
	return (cpy_new);
}
