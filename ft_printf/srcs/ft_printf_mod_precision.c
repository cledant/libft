/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 18:51:39 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 17:13:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_fill_next(char **new, size_t pre_len, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < (pre_len - s_len))
	{
		**new = '0';
		(*new)++;
		i++;
	}
}

char			*ft_printf_mod_precision(char *s, size_t pre_len)
{
	size_t	s_len;
	char	*new;
	char	*cpy_s;
	char	*cpy_new;

	if ((s_len = ft_strlen(s)) >= pre_len)
		return (s);
	cpy_s = s;
	if (ft_isdigit(*s) == 0)
		s_len--;
	if ((new = ft_strnew(pre_len + 1)) == NULL)
		return (NULL);
	cpy_new = new;
	if (ft_isdigit(*s) == 0)
	{
		*new = *s;
		new++;
		s++;
	}
	ft_fill_next(&new, pre_len, s_len);
	ft_strcpy(new, s);
	ft_strdel(&cpy_s);
	return (cpy_new);
}
