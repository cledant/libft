/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:26:33 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 17:01:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_next(char **new, size_t size_len, size_t s_len)
{
	size_t	i;

	i = 0;
	while (i < (size_len - s_len))
	{
		**new = '0';
		(*new)++;
		i++;
	}
}

char		*ft_printf_mod_size_zero(char *s, size_t size_len)
{
	size_t	s_len;
	char	*new;
	char	*cpy_s;
	char	*cpy_new;

	if ((s_len = ft_strlen(s)) >= size_len)
		return (s);
	cpy_s = s;
	if ((new = ft_strnew(size_len)) == NULL)
		return (NULL);
	cpy_new = new;
	if (ft_isalnum(*s) == 0)
	{
		*new = *s;
		new++;
		s++;
	}
	ft_fill_next(&new, size_len, s_len);
	ft_strcpy(new, s);
	ft_strdel(&cpy_s);
	return (cpy_new);
}
