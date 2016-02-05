/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 08:35:55 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:58:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read_cpy(char **perma_buff, char *buff, int ret_read)
{
	char	*tmp;

	tmp = ft_strnew(ret_read + ft_strlen(*perma_buff));
	if (tmp == NULL)
	{
		ft_strdel(perma_buff);
		return (-1);
	}
	ft_strcpy(tmp, *perma_buff);
	ft_strcat(tmp, buff);
	ft_strdel(perma_buff);
	*perma_buff = tmp;
	ft_bzero(buff, ret_read + 1);
	return (0);
}

static int	ft_read_buff(int fd, char **perma_buff, size_t *nb_ret_line)
{
	int		ret_read;
	char	buff[BUFF_SIZE + 1];

	ft_bzero(buff, BUFF_SIZE + 1);
	if ((ret_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		ft_strdel(perma_buff);
		*perma_buff = ft_strnew(0);
		if (perma_buff == NULL)
			return (-1);
		*nb_ret_line = 0;
	}
	while (ret_read > 0)
	{
		if (fd == 0 && ft_strchr(buff, '\n') != NULL)
		{
			if (ft_read_cpy(perma_buff, buff, ret_read) == -1)
				return (-1);
			return (ret_read);
		}
		if (ft_read_cpy(perma_buff, buff, ret_read) == -1)
			return (-1);
		ret_read = read(fd, buff, BUFF_SIZE);
	}
	return (ret_read);
}

static int	ft_check_end(char *cpy_perma_buff, size_t *nb_ret_line,
							char **line, char **perma_buff)
{
	*line = ft_strnew(0);
	if (line == NULL)
		return (-1);
	if (cpy_perma_buff == NULL)
		return (0);
	else if (*cpy_perma_buff == '\0' || *cpy_perma_buff == '\n' ||
				*cpy_perma_buff == 26)
	{
		if (*cpy_perma_buff == '\n')
		{
			(*nb_ret_line)++;
			return (1);
		}
		ft_strdel(perma_buff);
		return (0);
	}
	ft_strdel(line);
	return (2);
}

static int	ft_find_nextline(char *cpy_perma_buff, char **perma_buff,
								char **line, size_t *nbr_ret_line)
{
	size_t counter;

	counter = 0;
	while (*(cpy_perma_buff + counter) != '\n')
	{
		counter++;
		if (*(cpy_perma_buff + counter) == '\0' ||
				*(cpy_perma_buff + counter) == 26)
		{
			*line = ft_strnew(counter);
			if (line == NULL)
				return (-1);
			ft_strncpy(*line, cpy_perma_buff, counter);
			ft_strdel(perma_buff);
			return (0);
		}
	}
	(*nbr_ret_line)++;
	*line = ft_strnew(counter);
	if (line == NULL)
		return (-1);
	ft_strncpy(*line, cpy_perma_buff, counter);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static size_t	ret_line = 0;
	static char		*perma_buff;
	char			*cpy_perma_buff;
	size_t			counter;
	int				ret_read;

	counter = 0;
	if (line == NULL || fd < 0 || (BUFF_SIZE <= 0 && BUFF_SIZE > 7500000))
		return (-1);
	if (ft_read_buff(fd, &perma_buff, &ret_line) == -1)
		return (-1);
	cpy_perma_buff = perma_buff;
	while (counter < ret_line && cpy_perma_buff != NULL)
	{
		if (*cpy_perma_buff == '\n')
			counter++;
		cpy_perma_buff++;
	}
	ret_read = ft_check_end(cpy_perma_buff, &ret_line, line, &perma_buff);
	if (ret_read != 2)
		return (ret_read);
	ret_read = ft_find_nextline(cpy_perma_buff, &perma_buff, line, &ret_line);
	if (ret_read == -1 || ret_read == 0)
		ft_strdel(&perma_buff);
	return (ret_read);
}
