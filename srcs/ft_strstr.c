/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:45:40 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:37:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_val_reset(char **s1, char **cur_s1, char **s2, char **cpy_s2)
{
	*s1 = *cur_s1;
	*s2 = *cpy_s2;
}

char		*ft_strstr(const char *s1, const char *s2)
{
	char	*cpy_s2;
	char	*current_s1;

	current_s1 = NULL;
	cpy_s2 = (char *)s2;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			current_s1 = (char *)s1;
			while (*s1 != '\0' && *s1 == *s2)
			{
				s1++;
				s2++;
			}
			if (*s2 == '\0')
				return (current_s1);
			else
				ft_val_reset((char **)&s1, &current_s1, (char **)&s2, &cpy_s2);
		}
		s1++;
	}
	return (NULL);
}
