/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:06:46 by cledant           #+#    #+#             */
/*   Updated: 2016/05/05 10:29:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *s1)
{
	size_t	len_s1;
	wchar_t	*cpy_s1;

	len_s1 = 0;
	len_s1 = ft_wlen_strlen(s1);
	cpy_s1 = (wchar_t *)malloc((len_s1 + 1) * sizeof(wchar_t));
	if (cpy_s1 != NULL)
	{
		ft_bzero(cpy_s1, (len_s1 + 1) * sizeof(wchar_t));
		cpy_s1 = ft_wstrcpy(cpy_s1, s1);
	}
	return (cpy_s1);
}
