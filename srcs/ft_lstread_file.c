/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstread_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 14:41:53 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 15:57:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_read_routine(int ret, t_list *list, char *line)
{
	t_list	*new;

	if (ret == -1)
	{
		if (list != NULL)
			ft_lstdel(&list, &ft_bzero);
		return (0);
	}
	if (ret == 1 || (ret == 0 && *line != '\0'))
	{
		new = ft_lstnew(line, ft_strlen(line) + 1);
		if (new == NULL)
		{
			ft_lstdel(&list, &ft_bzero);
			ft_strdel(&line);
			return (0);
		}
		ft_lstpushback(list, new);
	}
	return (1);
}

t_list			*ft_lstread_file(int fd)
{
	t_list	*list;
	char	*line;
	int		ret;

	if (fd <= 0)
		return (NULL);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (NULL);
	list = ft_lstnew(line, ft_strlen(line) + 1);
	ft_strdel(&line);
	while ((ret = get_next_line(fd, &line)) == 1)
		if (ft_read_routine(ret, list, line) == 0)
			return (NULL);
	if (ft_read_routine(ret, list, line) == 0)
		return (NULL);
	return (list);
}
