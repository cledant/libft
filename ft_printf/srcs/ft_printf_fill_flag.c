/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_flag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:59:59 by cledant           #+#    #+#             */
/*   Updated: 2016/04/21 09:45:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_fill_flag(char *format, t_flags *data)
{
	if (ft_strncmp(format, "#", 1) == 0)
		data->sharp = 1;
	else if (ft_strncmp(format, "0", 1) == 0)
		data->pad_zero = 1;
	else if (ft_strncmp(format, "+", 1) == 0)
		data->sign = 1;
	else if (ft_strncmp(format, "-", 1) == 0)
		data->pad_space = 1;
	else if (ft_strncmp(format, " ", 1) == 0)
		data->space = 1;
}
