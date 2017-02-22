/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_front_n_remove.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:54:24 by cledant           #+#    #+#             */
/*   Updated: 2016/04/30 17:13:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_front_n_remove(char *s, size_t len)
{
	size_t	s_len;
	char	*new;
	char	*cpy_s;

	s_len = ft_strlen(s);
	if ((new = ft_strnew(s_len - len)) == NULL)
		return (s);
	cpy_s = s;
	ft_strcpy(new, s + len);
	ft_strdel(&cpy_s);
	return (new);
}
