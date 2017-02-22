/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 20:58:36 by cledant           #+#    #+#             */
/*   Updated: 2017/02/21 20:59:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strconcat(char const *s1, char const *s2, char c)
{
	size_t	len;
	char	*result;
	char	*cpy_result;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	result = ft_strnew(len);
	if (result == NULL)
		return (NULL);
	cpy_result = result;
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	*result = c;
	result++;
	while (*s2 != '\0')
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (cpy_result);
}
