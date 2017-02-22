/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_precision_str_simple.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:35:00 by cledant           #+#    #+#             */
/*   Updated: 2016/05/02 21:02:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_mod_precision_str_simple(char *s, size_t pre_size)
{
	size_t	s_len;
	char	*new;
	char	*cpy_new;
	char	*cpy_s;
	size_t	i;

	if ((s_len = ft_strlen(s)) <= pre_size)
		return (s);
	i = 0;
	if ((new = ft_strnew(pre_size + 1)) == NULL)
		return (NULL);
	cpy_new = new;
	cpy_s = s;
	while (i < pre_size)
	{
		*new = *s;
		new++;
		s++;
		i++;
	}
	ft_strdel(&cpy_s);
	return (cpy_new);
}
