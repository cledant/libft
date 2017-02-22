/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:07:47 by cledant           #+#    #+#             */
/*   Updated: 2016/05/02 21:25:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_other(t_flags *flags)
{
	char	*str;
	size_t	len;

	if (flags->other_char == 0)
	{
		if ((str = ft_strnew(1)) == NULL)
			return (0);
		*str = flags->other_char;
		if (flags->pad_size > 0)
			flags->pad_size--;
		str = ft_printf_chain_modifier(str, 0, flags);
		len = ft_strlen(str);
		ft_putchar(flags->other_char);
		ft_strdel(&str);
		return (1 + len);
	}
	if ((str = ft_strnew(1)) == NULL)
		return (0);
	*str = flags->other_char;
	str = ft_printf_chain_modifier(str, 0, flags);
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}
