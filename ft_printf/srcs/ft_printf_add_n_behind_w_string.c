/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:13:09 by cledant           #+#    #+#             */
/*   Updated: 2016/05/01 16:01:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_printf_add_n_behind_w_string(wchar_t *s, size_t p_len, char c)
{
	wchar_t		*ret;
	wchar_t		*s2;
	wchar_t		*cpy_s2;
	size_t		i;
	size_t		r_len;

	i = 0;
	if (p_len <= ft_wstrlen(s))
		return (s);
	r_len = p_len - ft_wstrlen(s);
	if ((s2 = ft_wstrnew(r_len)) == NULL)
		return (s);
	cpy_s2 = s2;
	while (i < r_len)
	{
		*s2 = c;
		s2++;
		i++;
	}
	if ((ret = ft_wstrjoin(s, cpy_s2)) == NULL)
		return (s);
	free(s);
	free(cpy_s2);
	return (ret);
}
