/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hhxx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:38:57 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 19:39:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_hhxx(va_list list_arg, int maj, t_flags *flag)
{
	int					val;
	unsigned char		disp_val;
	int					len;
	char				*s_val;

	val = va_arg(list_arg, int);
	if (val < 0)
		disp_val = (unsigned char)val;
	else
		disp_val = (unsigned char)val;
	if ((s_val = ft_printf_hex_converter(disp_val)) == NULL)
		return (0);
	s_val = ft_printf_chain_modifier(s_val, val, flag);
	len = ft_strlen(s_val);
	if (maj == 1)
		ft_strtoupper(s_val);
	ft_putstr(s_val);
	ft_strdel(&s_val);
	return (len);
}
