/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 18:22:47 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 17:07:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_lc(va_list list_arg, t_flags *flags)
{
	int			val;
	wchar_t		*str;
	size_t		len;

	if ((str = ft_wstrnew(1)) == NULL)
		return (0);
	if ((val = va_arg(list_arg, wchar_t)) == 0)
	{
		*str = val;
		if (flags->pad_size > 0)
			flags->pad_size--;
		str = ft_printf_chain_modifier_w(str, 0, flags);
		len = ft_wstrlen(str);
		ft_wputstr(str);
		ft_wputchar(val);
		free(str);
		return (1 + len);
	}
	*str = val;
	str = ft_printf_chain_modifier_w(str, 0, flags);
	len = ft_wstrlen(str);
	ft_wputstr(str);
	free(str);
	return (len);
}
