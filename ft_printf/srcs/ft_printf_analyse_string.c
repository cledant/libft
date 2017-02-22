/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse_type.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 14:25:34 by cledant           #+#    #+#             */
/*   Updated: 2016/05/04 17:19:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_create_char(size_t len, char *format)
{
	char	*type;

	if ((type = ft_strnew(len)) == NULL)
		return (NULL);
	else
		ft_memcpy(type, format, len);
	return (type);
}

static void		ft_increment(size_t *len, char **cpy_format, int *flag_flag,
					int set_at)
{
	(*len)++;
	(*cpy_format)++;
	if (set_at != -1)
		*flag_flag = set_at;
}

static int		ft_part_1(size_t *len, char **cpy_format, int *flag_flag,
					int (*same_flag)[3])
{
	if (*flag_flag >= 6 && ft_printf_is_flag(*cpy_format) == 1)
	{
		ft_increment(len, cpy_format, flag_flag, -1);
		(*same_flag)[2] = 1;
	}
	else if (*flag_flag >= 5 && ft_isdigit(**cpy_format) == 1)
	{
		ft_increment(len, cpy_format, flag_flag, 5);
		(*same_flag)[2] = 1;
	}
	else if (*flag_flag >= 4 && ft_strncmp(*cpy_format, ".", 1) == 0)
	{
		if ((*same_flag)[0] > 0)
			return (-1);
		(*same_flag)[0]++;
		ft_increment(len, cpy_format, flag_flag, 4);
		(*same_flag)[2] = 1;
	}
	else if (*flag_flag >= 3 && ft_isdigit(**cpy_format) == 1)
	{
		ft_increment(len, cpy_format, flag_flag, 3);
		(*same_flag)[2] = 1;
	}
	return (0);
}

static int		ft_part_2(size_t *len, char **cpy_format, int (*same_flag)[3],
					int *flag_flag)
{
	size_t	res_flag_2;

	res_flag_2 = ft_printf_is_modifier(*cpy_format);
	if ((*same_flag)[1] > 0)
		return (-1);
	(*same_flag)[1]++;
	*len += res_flag_2;
	*cpy_format += res_flag_2;
	*flag_flag = 2;
	return (0);
}

char			*ft_printf_analyse_string(char *format)
{
	char	*cpy_format;
	int		flag_flag;
	int		same_flag[3];
	size_t	len;

	ft_printf_init_analyse(&flag_flag, &len, &cpy_format, format);
	ft_bzero(same_flag, 12);
	if (ft_strncmp(cpy_format, "%", 1) == 0)
		return (ft_create_char(1, format));
	while (*cpy_format != '\0')
	{
		if (ft_part_1(&len, &cpy_format, &flag_flag, &same_flag) == -1)
			return (NULL);
		if (same_flag[2] == 0 && flag_flag >= 2
			&& ft_printf_is_modifier(cpy_format) > 0
				&& ft_part_2(&len, &cpy_format, &same_flag, &flag_flag) == -1)
			return (NULL);
		else if (same_flag[2] == 0 && flag_flag >= 1)
			return (ft_create_char(++len, format));
		else if (same_flag[2] == 0)
			return (NULL);
		same_flag[2] = 0;
	}
	return (NULL);
}
