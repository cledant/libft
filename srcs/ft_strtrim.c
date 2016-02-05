/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:03:27 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:50:07 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char *s, size_t result)
{
	while (*s != '\0')
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
		{
			while (*s == ' ' || *s == '\n' || *s == '\t')
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
		else
		{
			result++;
			while (*s != ' ' && *s != '\n' && *s != '\t')
			{
				if (*s == '\0')
					return (result);
				s++;
			}
		}
	}
	return (result);
}

static void		ft_val_inc(size_t *result, char **s)
{
	(*result)++;
	(*s)++;
}

static size_t	ft_strtrimlen(char const *s)
{
	size_t	result;
	size_t	counter;
	size_t	words;

	result = 0;
	words = 0;
	counter = 0;
	words = ft_word_count((char *)s, words);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s != '\0' && counter < words)
	{
		while (*s != ' ' && *s != '\n' && *s != '\t')
			ft_val_inc(&result, (char **)&s);
		counter++;
		if (counter == words)
			return (result);
		while (*s == ' ' || *s == '\n' || *s == '\t')
			ft_val_inc(&result, (char **)&s);
	}
	return (result);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	char	*cpy_res;
	size_t	len;
	size_t	counter;

	counter = 0;
	len = ft_strtrimlen(s);
	result = ft_strnew(len);
	if (result == NULL)
		return (result);
	cpy_res = result;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (counter < len)
	{
		*result = *s;
		s++;
		result++;
		counter++;
	}
	return (cpy_res);
}
