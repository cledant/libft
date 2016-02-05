/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_till_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 19:39:21 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:31:36 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_till_char(const char *s, int c)
{
	size_t length;

	length = 0;
	while (*s != '\0' && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}
