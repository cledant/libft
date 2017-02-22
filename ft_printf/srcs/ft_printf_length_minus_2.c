/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:21:49 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 11:20:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_pf_next(va_list list_arg, t_flags *flag)
{
	int		len;

	len = 0;
	if (flag->type == 9)
		len = ft_printf_lu(list_arg, flag);
	else if (flag->type == 10)
		len = ft_printf_hhxx(list_arg, 0, flag);
	else if (flag->type == 11)
		len = ft_printf_hhxx(list_arg, 1, flag);
	else if (flag->type == 12)
		len = ft_printf_c(list_arg, flag);
	else if (flag->type == 13)
		len = ft_printf_lc(list_arg, flag);
	else if (flag->type == 100)
		len = ft_printf_other(flag);
	return (len);
}

int				ft_printf_length_minus_2(t_flags *flag, va_list list_arg)
{
	int		len;

	len = 0;
	if (flag->type == 0)
		len = ft_printf_s(list_arg, flag);
	else if (flag->type == 1)
		len = ft_printf_ls(list_arg, flag);
	else if (flag->type == 2)
		len = ft_printf_p(list_arg, flag);
	else if (flag->type == 3)
		len = ft_printf_hhd(list_arg, flag);
	else if (flag->type == 4)
		len = ft_printf_ld(list_arg, flag);
	else if (flag->type == 5)
		len = ft_printf_hhd(list_arg, flag);
	else if (flag->type == 6)
		len = ft_printf_hho(list_arg, flag);
	else if (flag->type == 7)
		len = ft_printf_lo(list_arg, flag);
	else if (flag->type == 8)
		len = ft_printf_hhu(list_arg, flag);
	else
		len = ft_pf_next(list_arg, flag);
	return (len);
}
