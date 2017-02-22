/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_flag_zero_sc.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 12:50:30 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 12:50:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_set_flag_zero_sc(t_flags *f)
{
	f->precision = 0;
	f->preci_size = 0;
	f->space = 0;
	f->pad_zero = 0;
	f->pad_space = 0;
	f->pad_size = 0;
}
