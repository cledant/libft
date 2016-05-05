/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:52:10 by cledant           #+#    #+#             */
/*   Updated: 2016/04/28 18:34:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t		*loc;

	loc = (wchar_t *)malloc((size + 1) * sizeof(wchar_t));
	if (loc != NULL)
		ft_bzero(loc, (size + 1) * sizeof(wchar_t));
	return (loc);
}
