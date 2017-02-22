/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_llu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 19:22:12 by cledant           #+#    #+#             */
/*   Updated: 2016/04/28 11:38:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_llu(va_list list_arg, t_flags *flag)
{
	long long int			val;
	unsigned long long int	disp_val;
	int						len;
	char					*s_val;

	val = va_arg(list_arg, long long int);
	if (val < 0)
		disp_val = (unsigned long long int)val;
	else
		disp_val = val;
	if ((s_val = ft_printf_itoa_unsigned_long_long_int(disp_val)) == NULL)
		return (0);
	s_val = ft_printf_chain_modifier_ull(s_val, disp_val, flag);
	ft_putstr(s_val);
	len = ft_strlen(s_val);
	ft_strdel(&s_val);
	return (len);
}
