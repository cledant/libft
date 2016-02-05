/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_char2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 18:23:47 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:13:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strdup_char2(char **str)
{
	size_t	index_count;
	char	**ret;
	size_t	i;

	i = 0;
	index_count = ft_char2_index_size(str);
	if ((ret = (char **)malloc(sizeof(char *) * (index_count + 1))) == NULL)
		return (NULL);
	while (i < index_count + 1)
		ret[i++] = NULL;
	i = 0;
	while (i < index_count)
	{
		if ((ret[i] = ft_strdup(str[i])) == NULL)
		{
			ft_strdel_char2(&ret);
			return (NULL);
		}
		i++;
	}
	if (index_count == 0)
		ret[0] = NULL;
	return (ret);
}
