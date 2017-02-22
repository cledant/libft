/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ho.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:01:04 by cledant           #+#    #+#             */
/*   Updated: 2016/04/27 09:55:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_ho(va_list list_arg, t_flags *flag)
{
	int					val;
	unsigned short int	disp_val;
	int					len;
	char				*s_val;

	val = va_arg(list_arg, int);
	if (val < 0)
		disp_val = (unsigned short int)val;
	else
		disp_val = (unsigned short int)val;
	if ((s_val = ft_printf_octal_converter(disp_val)) == NULL)
		return (0);
	s_val = ft_printf_chain_modifier(s_val, disp_val, flag);
	len = ft_strlen(s_val);
	ft_putstr(s_val);
	ft_strdel(&s_val);
	return (len);
}
