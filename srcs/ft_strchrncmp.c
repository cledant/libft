/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrncmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 09:17:51 by cledant           #+#    #+#             */
/*   Updated: 2017/02/22 09:17:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrncmp(const char *s1, const char s2, size_t n)
{
	int		result;
	size_t	counter;

	if (n == 0)
		return (0);
	counter = 1;
	result = 0;
	while (counter < n)
	{
		if (*s1 == '\0')
			return (*(unsigned char *)s1 - (unsigned char)s2);
		s1++;
	}
	result = *(unsigned char *)s1 - (unsigned char)s2;
	return (result);
}
