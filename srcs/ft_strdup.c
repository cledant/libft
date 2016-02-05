/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:06:46 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:34:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*cpy_s1;

	len_s1 = 0;
	len_s1 = ft_strlen(s1);
	cpy_s1 = (char *)malloc((len_s1 + 1) * sizeof(char));
	ft_bzero(cpy_s1, len_s1 + 1);
	if (cpy_s1 != NULL)
		cpy_s1 = ft_strcpy(cpy_s1, s1);
	return (cpy_s1);
}
