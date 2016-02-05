/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:19:24 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:36:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	result;

	result = 0;
	while (*(unsigned char *)s1 == *(unsigned char *)s2)
	{
		result = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (*s1 == '\0')
			return (result);
		s1++;
		s2++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
