/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 16:04:32 by cledant           #+#    #+#             */
/*   Updated: 2016/05/05 10:34:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	size_t		len;
	wchar_t		*result;
	wchar_t		*cpy_result;

	len = ft_wstrlen(s1);
	len = len + ft_wstrlen(s2);
	if ((result = ft_wstrnew(len)) == NULL)
		return (NULL);
	cpy_result = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (cpy_result);
}
