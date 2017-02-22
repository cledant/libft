/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 10:43:42 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 18:54:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_pf_next(va_list list_arg, t_flags *flag)
{
	int		len;

	len = 0;
	if (flag->type == 9)
		len = ft_printf_llu(list_arg, flag);
	else if (flag->type == 10)
		len = ft_printf_llxx(list_arg, 0, flag);
	else if (flag->type == 11)
		len = ft_printf_llxx(list_arg, 1, flag);
	else if (flag->type == 12)
		len = ft_printf_c(list_arg, flag);
	else if (flag->type == 13)
		len = ft_printf_lc(list_arg, flag);
	else if (flag->type == 100)
		len = ft_printf_other(flag);
	return (len);
}

int				ft_printf_length_2(t_flags *flag, va_list list_arg)
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
		len = ft_printf_lld(list_arg, flag);
	else if (flag->type == 4)
		len = ft_printf_lld(list_arg, flag);
	else if (flag->type == 5)
		len = ft_printf_lld(list_arg, flag);
	else if (flag->type == 6)
		len = ft_printf_llo(list_arg, flag);
	else if (flag->type == 7)
		len = ft_printf_llo(list_arg, flag);
	else if (flag->type == 8)
		len = ft_printf_llu(list_arg, flag);
	else
		len = ft_pf_next(list_arg, flag);
	return (len);
}
