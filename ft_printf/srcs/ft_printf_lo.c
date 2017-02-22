/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:26:17 by cledant           #+#    #+#             */
/*   Updated: 2016/04/27 10:53:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_lo(va_list list_arg, t_flags *flag)
{
	long int			val;
	unsigned long int	disp_val;
	int					len;
	char				*s_val;

	val = va_arg(list_arg, long int);
	if (val < 0)
		disp_val = (unsigned long int)val;
	else
		disp_val = val;
	if ((s_val = ft_printf_octal_converter_long_int(disp_val)) == NULL)
		return (0);
	s_val = ft_printf_chain_modifier(s_val, disp_val, flag);
	len = ft_strlen(s_val);
	ft_putstr(s_val);
	ft_strdel(&s_val);
	return (len);
}
