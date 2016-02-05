/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 14:17:38 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:48:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	counter;
	char			*fresh;
	char			*cpy_fresh;
	size_t			len;

	counter = 0;
	len = ft_strlen(s);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (fresh);
	cpy_fresh = fresh;
	while (*s != '\0')
	{
		*fresh = (*f)(counter, *s);
		counter++;
		s++;
		fresh++;
	}
	*fresh = '\0';
	return (cpy_fresh);
}
