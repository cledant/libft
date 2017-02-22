/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 11:30:42 by cledant           #+#    #+#             */
/*   Updated: 2016/05/10 16:19:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_first(char **cpy_ft, size_t *read_c,
					size_t *ret_parse)
{
	(*cpy_ft)++;
	ft_putchar(**cpy_ft);
	(*cpy_ft)++;
	(*read_c)++;
	(*ret_parse) = -1;
}

static void		ft_printf_second(char **cpy_ft, size_t *read_c)
{
	if (*(cpy_ft + 1) != NULL && **(cpy_ft + 1) != '\0' &&
			ft_isspace(**(cpy_ft + 1)) == 1)
	{
		(*cpy_ft)++;
		while (ft_isspace(**cpy_ft) == 1)
			(*cpy_ft)++;
		ft_putchar(**cpy_ft);
		(*cpy_ft)++;
		(*read_c)++;
	}
	else
		(*cpy_ft)++;
}

static void		ft_printf_third(char **cpy_ft, size_t *read_c)
{
	ft_putchar(**cpy_ft);
	(*cpy_ft)++;
	(*read_c)++;
}

static void		ft_printf_cases(int skip, char **cpy_ft, size_t *read_c,
					size_t *ret_parse)
{
	if (skip == 1)
		ft_printf_first(cpy_ft, read_c, ret_parse);
	if (*ret_parse == 0)
		ft_printf_second(cpy_ft, read_c);
	else
		(*cpy_ft) += (*ret_parse) + 1;
}

int				ft_printf(const char *restrict format, ...)
{
	va_list list;
	size_t	read_c;
	size_t	ret_parse;
	int		skip;
	char	*cpy_ft;

	cpy_ft = (char *)format;
	read_c = 0;
	va_start(list, format);
	while (*cpy_ft != '\0')
	{
		skip = 0;
		if (ft_strncmp(cpy_ft, "%", 1) == 0)
		{
			ret_parse = ft_printf_parse_type(cpy_ft, list, &skip, &read_c);
			ft_printf_cases(skip, &cpy_ft, &read_c, &ret_parse);
		}
		else
			ft_printf_third(&cpy_ft, &read_c);
		ret_parse = 0;
	}
	va_end(list);
	return (read_c);
}
