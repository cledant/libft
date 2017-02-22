/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 18:44:06 by cledant           #+#    #+#             */
/*   Updated: 2016/04/20 18:44:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_is_flag(char *format)
{
	char	flag[6];
	size_t	i;

	i = 0;
	ft_strcpy(flag, "#0-+ \0");
	while (i < 6)
	{
		if (*format == flag[i])
			return (1);
		i++;
	}
	return (0);
}
