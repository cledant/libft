/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:21:49 by cledant           #+#    #+#             */
/*   Updated: 2016/05/10 12:55:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf_print_args(t_flags *flag, va_list list_arg)
{
	int		len;

	len = 0;
	if (flag->length == 0)
		len = ft_printf_length_0(flag, list_arg);
	else if (flag->length == 1)
		len = ft_printf_length_1(flag, list_arg);
	else if (flag->length == 2)
		len = ft_printf_length_2(flag, list_arg);
	else if (flag->length == -1)
		len = ft_printf_length_minus_1(flag, list_arg);
	else if (flag->length == -2)
		len = ft_printf_length_minus_2(flag, list_arg);
	else if (flag->length == 10)
		len = ft_printf_length_j(flag, list_arg);
	else if (flag->length == 20)
		len = ft_printf_length_z(flag, list_arg);
	return (len);
}
