/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:25:34 by cledant           #+#    #+#             */
/*   Updated: 2016/04/27 14:51:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_printf_parse_type(char *format, va_list list_arg,
					int *skip, size_t *nb_print)
{
	char	*parse;
	size_t	ret;
	t_flags	flag;

	if ((parse = ft_printf_analyse_string(format + 1)) != NULL)
	{
		ft_printf_init_data(&flag);
		ft_printf_setup_data(parse, &flag);
		ret = ft_strlen(parse);
		*nb_print += ft_printf_print_args(&flag, list_arg);
		if (ft_strcmp(parse, "%") == 0)
			*skip = 1;
		ft_strdel(&parse);
		return (ret);
	}
	return (0);
}
