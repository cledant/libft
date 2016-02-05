/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_alphanum.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 10:37:38 by cledant           #+#    #+#             */
/*   Updated: 2016/01/28 10:40:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_str_alphanum(char *str)
{
	int		result;

	result = 0;
	while (*str != '\0')
	{
		if (ft_isalnum(*str) == 0)
			return (0);
		else
			result = 1;
		str++;
	}
	return (result);
}
