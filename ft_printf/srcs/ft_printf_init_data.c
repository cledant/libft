/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 16:59:21 by cledant           #+#    #+#             */
/*   Updated: 2016/05/02 17:22:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init_data(t_flags *data)
{
	data->space = 0;
	data->sharp = 0;
	data->pad_zero = 0;
	data->pad_space = 0;
	data->pad_size = 0;
	data->sign = 0;
	data->precision = 0;
	data->preci_size = 0;
	data->double_pc = 0;
	data->length = 0;
	data->type = -1;
	data->other_char = 0;
}
