/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chain_modifier_w.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 17:21:42 by cledant           #+#    #+#             */
/*   Updated: 2016/05/01 15:52:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*ft_printf_chain_modifier_w(wchar_t *s, long long int val, t_flags *f)
{
	if (f->precision == 1 && (f->type == 13 || f->type == 1))
		s = ft_printf_mod_precision_str_w(s, f->preci_size);
	if (f->pad_space == 1 && (f->type == 13 || f->type == 1))
		s = ft_printf_add_n_behind_w_string(s, f->pad_size, ' ');
	if (f->pad_zero == 0 && f->pad_space == 0 && (f->type == 13 ||
			f->type == 1))
		s = ft_printf_mod_size_w(s, f->pad_size);
	if (f->pad_zero == 1 && f->pad_space == 0 && (f->type == 13 ||
			f->type == 1))
		s = ft_printf_mod_size_zero_w(s, f->pad_size);
	val++;
	return (s);
}
