/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 14:27:32 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:36:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cpy_s1;
	size_t	counter;

	counter = 0;
	cpy_s1 = s1;
	if (n == 0)
		return (s1);
	while (*s1 != '\0')
		s1++;
	while (*s2 != '\0' && counter < n)
	{
		*s1 = *s2;
		s1++;
		s2++;
		counter++;
	}
	*s1 = '\0';
	return (cpy_s1);
}
