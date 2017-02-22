/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:07:47 by cledant           #+#    #+#             */
/*   Updated: 2016/05/01 20:14:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_s(va_list list_arg, t_flags *flag)
{
	char	*val;
	char	*m_val;
	size_t	len;

	val = va_arg(list_arg, char *);
	if (val == NULL)
	{
		if ((m_val = ft_strnew(6)) == NULL)
			return (0);
		ft_strcpy(m_val, "(null)");
		m_val = ft_printf_chain_modifier(m_val, -1, flag);
		ft_putstr(m_val);
		len = ft_strlen(m_val);
		ft_strdel(&m_val);
		return (len);
	}
	if ((m_val = ft_strdup(val)) == NULL)
		return (0);
	m_val = ft_printf_chain_modifier(m_val, 0, flag);
	ft_putstr(m_val);
	len = ft_strlen(m_val);
	ft_strdel(&m_val);
	return (len);
}
