/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:07:47 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 13:21:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_c(va_list list_arg, t_flags *flags)
{
	int		val;
	char	*str;
	size_t	len;

	if ((str = ft_strnew(1)) == NULL)
		return (0);
	if ((val = va_arg(list_arg, int)) == 0)
	{
		*str = val;
		if (flags->pad_size > 0)
			flags->pad_size--;
		str = ft_printf_chain_modifier(str, 0, flags);
		len = ft_strlen(str);
		ft_putstr(str);
		ft_putchar(val);
		ft_strdel(&str);
		return (1 + len);
	}
	*str = val;
	str = ft_printf_chain_modifier(str, 0, flags);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}
