/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:19:24 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:36:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	counter;

	result = 0;
	counter = 1;
	if (n == 0)
		return (0);
	while (counter < n && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		result = *(unsigned char *)s1 - *(unsigned char *)s2;
		if (*s1 == '\0')
			return (result);
		s1++;
		s2++;
		counter++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
