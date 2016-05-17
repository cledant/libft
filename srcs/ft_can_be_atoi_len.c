/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_can_be_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:05:15 by cledant           #+#    #+#             */
/*   Updated: 2016/05/17 11:41:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_number_len(char *c)
{
	size_t	i;

	i = 0;
	while (*c != '\0' && ft_isdigit(*c) == 1)
	{
		i++;
		c++;
	}
	return (i);
}

size_t					ft_can_be_atoi_len(char *c)
{
	while (ft_isspace(*c) == 1)
		c++;
	if (*c == '+' || *c == '-')
	{
		c++;
		if (*c >= '0' && *c <= '9')
			return (ft_number_len(c));
		else
			return (0);
	}
	else if (*c >= '0' && *c <= '9')
		return (ft_number_len(c));
	else
		return (0);
}
