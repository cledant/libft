/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_init_analyse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 17:18:16 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 17:18:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_init_analyse(int *flag_flag, size_t *len,
					char **cpy_format, char *format)
{
	*flag_flag = 6;
	*len = 0;
	*cpy_format = format;
}
