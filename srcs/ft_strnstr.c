/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:45:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:38:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_val_reset2(char **s1, char **cur_s1, char **s2, char **cpy_s2)
{
	*s1 = *cur_s1;
	*s2 = *cpy_s2;
}

static void	ft_val_inc(char **s1, char **s2, size_t *counter)
{
	(*s1)++;
	(*s2)++;
	(counter[0])++;
}

static void	ft_init(char **cur_s1, char **s2, char **cpy_s2, size_t *count)
{
	*cur_s1 = NULL;
	count[0] = 0;
	count[1] = 0;
	*cpy_s2 = *s2;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*cpy_s2;
	char	*current_s1;
	size_t	counter[2];

	ft_init(&current_s1, (char **)&s2, &cpy_s2, counter);
	if (*s2 == '\0')
		return ((char *)s1);
	while (counter[0] < n && *s1 != '\0')
	{
		counter[1] = counter[0];
		if (*s1 == *s2)
		{
			current_s1 = (char *)s1;
			while (*s1 != '\0' && *s1 == *s2 && counter[0] < n)
				ft_val_inc((char **)&s1, (char **)&s2, counter);
			if (*s2 == '\0')
				return (current_s1);
			else
				ft_val_reset2((char **)&s1, &current_s1, (char **)&s2, &cpy_s2);
		}
		counter[0] = counter[1];
		(counter[0])++;
		s1++;
	}
	return (NULL);
}
