/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chain_modifier_ull.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:18:22 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 13:18:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_pf_part_12(char *s, t_flags *f)
{
	if (f->preci_size == 0)
		s = ft_printf_mod_precision(s, 0);
	else if (f->pad_zero == 1 && f->pad_space == 0)
	{
		s = ft_printf_mod_size_zero(s, f->pad_size - 1);
		s = ft_printf_mod_precision(s, f->preci_size - 1);
	}
	else
		s = ft_printf_mod_precision(s, f->preci_size - 1);
	s = ft_printf_add_front_string("0", s);
	return (s);
}

static char		*ft_pf_part1(char *s, t_flags *f, unsigned long long int val)
{
	if ((f->type == 6 || f->type == 7) && f->sharp > 0 && val > 0)
		s = ft_pf_part_12(s, f);
	else if ((f->type == 10 || f->type == 11) && f->sharp > 0 && val > 0)
	{
		if (f->pad_zero == 1 && f->pad_space == 0)
		{
			s = ft_printf_mod_size_zero(s, f->pad_size - 2);
			s = ft_printf_mod_precision(s, f->preci_size);
		}
		else
			s = ft_printf_mod_precision(s, f->preci_size);
		s = ft_printf_add_front_string("0x", s);
	}
	else if ((f->type == 10 || f->type == 11) && f->sharp > 0 && val == 0 &&
			f->precision == 1)
		s = ft_printf_mod_rm_preci(s);
	return (s);
}

static char		*ft_pf_part2(char *s, t_flags *f, unsigned long long int val)
{
	if (f->precision == 1 && f->sharp == 0 && (f->type >= 2 && f->type <= 11))
		s = ft_printf_mod_precision(s, f->preci_size);
	if (f->precision == 1 && f->preci_size == 0 && (f->type >= 2
			&& f->type <= 11) && f->sharp == 0 && val == 0)
		s = ft_printf_mod_rm_preci(s);
	if (f->type == 2 && f->sharp == 0)
		s = ft_printf_add_front_string("0x", s);
	if (f->precision == 1 && (f->type == 12 || f->type == 0) && f->sharp == 0)
		s = ft_printf_mod_precision_str_simple(s, f->preci_size);
	if (f->precision == 1 && f->type == 100 && f->sharp == 0 &&
			f->preci_size >= 1)
		s = ft_printf_mod_precision_str_simple(s, f->preci_size - 1);
	if ((f->type == 3 || f->type == 4 || f->type == 5) && f->space > 0 &&
			f->sign == 0)
		s = ft_printf_add_front_string(" ", s);
	else if ((f->type == 3 || f->type == 4 || f->type == 5) && f->sign > 0)
		s = ft_printf_add_front_string("+", s);
	if (f->pad_zero == 0 && f->pad_space == 0 && (f->type >= 2 &&
			f->type <= 11))
		s = ft_printf_mod_size(s, f->pad_size);
	if (f->pad_zero == 0 && f->pad_space == 0 && (f->type == 12 ||
			f->type == 0 || f->type == 100))
		s = ft_printf_mod_size(s, f->pad_size);
	return (s);
}

static char		*ft_pf_part3(char *s, t_flags *f)
{
	if (f->pad_zero == 1 && f->pad_space == 0 && (f->type >= 3 &&
			f->type <= 11) && f->sharp == 0)
		s = ft_printf_mod_size_zero(s, f->pad_size);
	if (f->pad_zero == 1 && f->pad_space == 0 && (f->type == 12 ||
			f->type == 0 || f->type == 100))
		s = ft_printf_mod_size_zero_string(s, f->pad_size);
	if (f->pad_zero == 1 && f->pad_space == 0 && f->type == 2)
		s = ft_printf_mod_size_zero_hex(s, f->pad_size);
	if (f->pad_space == 1 && (f->type >= 2 && f->type <= 11))
		s = ft_printf_add_n_behind_string(s, f->pad_size, ' ');
	if (f->pad_space == 1 && (f->type == 12 || f->type == 0 || f->type == 100))
		s = ft_printf_add_n_behind_string(s, f->pad_size, ' ');
	return (s);
}

char			*ft_printf_chain_modifier_ull(char *s,
					unsigned long long int val, t_flags *f)
{
	if (f->pad_zero == 1 && f->precision == 1 && f->type != 0 && f->type != 12
			&& f->type != 100)
		f->pad_zero = 0;
	if (f->type == 0 && ft_strcmp(s, "") == 1)
		ft_printf_set_flag_zero_sc(f);
	s = ft_pf_part1(s, f, val);
	s = ft_pf_part2(s, f, val);
	s = ft_pf_part3(s, f);
	return (s);
}
