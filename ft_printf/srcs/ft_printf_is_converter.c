/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:41:40 by cledant           #+#    #+#             */
/*   Updated: 2016/04/20 18:42:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_is_converter(char *format)
{
	char	conv[15];
	size_t	i;

	i = 0;
	ft_strcpy(conv, "sSpdDioOuUxXcC\0");
	while (i < 15)
	{
		if (*format == conv[i])
			return (1);
		i++;
	}
	return (0);
}
