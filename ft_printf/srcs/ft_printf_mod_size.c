/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:26:33 by cledant           #+#    #+#             */
/*   Updated: 2016/04/28 16:26:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_mod_size(char *s, size_t size_len)
{
	size_t	s_len;
	char	*new;
	char	*cpy_new;
	size_t	i;

	if ((s_len = ft_strlen(s)) >= size_len)
		return (s);
	i = 0;
	if ((new = ft_strnew(size_len)) == NULL)
		return (NULL);
	cpy_new = new;
	while (i < (size_len - s_len))
	{
		*new = ' ';
		new++;
		i++;
	}
	ft_strcpy(new, s);
	ft_strdel(&s);
	return (cpy_new);
}
