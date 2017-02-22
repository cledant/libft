/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:13:09 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 13:08:19 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_printf_add_n_behind_string(char *s, size_t p_len, char c)
{
	char	*ret;
	char	*s2;
	char	*cpy_s2;
	size_t	i;
	size_t	r_len;

	i = 0;
	if (p_len <= ft_strlen(s))
		return (s);
	r_len = p_len - ft_strlen(s);
	if ((s2 = ft_strnew(r_len)) == NULL)
		return (s);
	cpy_s2 = s2;
	while (i < r_len)
	{
		*s2 = c;
		s2++;
		i++;
	}
	if ((ret = ft_strjoin(s, cpy_s2)) == NULL)
		return (s);
	ft_strdel(&s);
	ft_strdel(&cpy_s2);
	return (ret);
}
