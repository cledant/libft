/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_char2_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:41:59 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 10:05:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strnew_char2(size_t size)
{
	char	**ret;
	size_t	i;

	i = 0;
	if ((ret = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		ret[i] = NULL;
		i++;
	}
	return (ret);
}
