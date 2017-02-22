/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fill_modifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 19:06:46 by cledant           #+#    #+#             */
/*   Updated: 2016/04/20 20:06:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_fill_modifier(char *format, t_flags *data)
{
	if (ft_strncmp(format, "h", 1) == 0)
		data->length--;
	else if (ft_strncmp(format, "l", 1) == 0)
		data->length++;
	else if (ft_strncmp(format, "j", 1) == 0)
		data->length = 10;
	else if (ft_strncmp(format, "z", 1) == 0)
		data->length = 20;
}
