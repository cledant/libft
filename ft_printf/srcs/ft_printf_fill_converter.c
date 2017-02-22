/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_converter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:16:12 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 17:27:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_next_conv(char *format, t_flags *data)
{
	if (ft_strncmp(format, "U", 1) == 0)
		data->type = 9;
	else if (ft_strncmp(format, "x", 1) == 0)
		data->type = 10;
	else if (ft_strncmp(format, "X", 1) == 0)
		data->type = 11;
	else if (ft_strncmp(format, "c", 1) == 0)
		data->type = 12;
	else if (ft_strncmp(format, "C", 1) == 0)
		data->type = 13;
	else
	{
		data->type = 100;
		data->other_char = *format;
	}
}

void			ft_printf_fill_converter(char *format, t_flags *data)
{
	if (ft_strncmp(format, "s", 1) == 0)
		data->type = 0;
	else if (ft_strncmp(format, "S", 1) == 0)
		data->type = 1;
	else if (ft_strncmp(format, "p", 1) == 0)
		data->type = 2;
	else if (ft_strncmp(format, "d", 1) == 0)
		data->type = 3;
	else if (ft_strncmp(format, "D", 1) == 0)
		data->type = 4;
	else if (ft_strncmp(format, "i", 1) == 0)
		data->type = 5;
	else if (ft_strncmp(format, "o", 1) == 0)
		data->type = 6;
	else if (ft_strncmp(format, "O", 1) == 0)
		data->type = 7;
	else if (ft_strncmp(format, "u", 1) == 0)
		data->type = 8;
	else
		ft_next_conv(format, data);
}
