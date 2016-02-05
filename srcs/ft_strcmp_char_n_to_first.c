/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_char_n_to_first.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 08:59:18 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 10:02:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_char_n_to_first(const char *s1, const char *s2, size_t n)
{
	int		result;
	size_t	counter;

	counter = 1;
	result = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (*s1 == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
	}
	result = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (result);
}
