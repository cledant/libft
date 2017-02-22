/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:02:36 by cledant           #+#    #+#             */
/*   Updated: 2016/05/01 19:02:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_hu(va_list list_arg, t_flags *flag)
{
	int					val;
	unsigned short int	disp_val;
	int					len;
	char				*s_val;

	val = va_arg(list_arg, int);
	if (val < 0)
		disp_val = (unsigned short int)val;
	else
		disp_val = val;
	if ((s_val = ft_printf_itoa_unsigned(disp_val)) == NULL)
		return (0);
	s_val = ft_printf_chain_modifier_ull(s_val, disp_val, flag);
	ft_putstr(s_val);
	len = ft_strlen(s_val);
	ft_strdel(&s_val);
	return (len);
}
