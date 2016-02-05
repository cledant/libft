/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_char2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:52:48 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:15:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strcpy_char2(char **dst, char **src)
{
	char	**cpy_dst;

	cpy_dst = dst;
	while (src != NULL && *src != '\0')
	{
		if ((*dst = ft_strdup(*src)) == NULL)
		{
			ft_strdel_char2(&cpy_dst);
			return (NULL);
		}
		dst++;
		src++;
	}
	return (cpy_dst);
}
