/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstread_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:41:53 by cledant           #+#    #+#             */
/*   Updated: 2017/02/22 11:19:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstread_fd(int fd)
{
	t_list	*list;
	int		ret;
	char	*line;

	if (fd < 0)
		return (NULL);
	list = NULL;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if ((list = ft_lstneworpushback(list, line, (ft_strlen(line) + 1)))
				== NULL)
			return (NULL);
		if (line != NULL)
			free(line);
	}
	if (ret == 0)
	{
		if ((list = ft_lstneworpushback(list, line, (ft_strlen(line) + 1)))
				== NULL)
			return (NULL);
		if (line != NULL)
			free(line);
	}
	return (list);
}
