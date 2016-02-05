/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_only_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:11:03 by cledant           #+#    #+#             */
/*   Updated: 2016/01/27 13:32:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_str_only_spaces(char *str)
{
	int		result;

	result = 0;
	while (*str != '\0')
	{
		if (ft_isspace(*str) == 0)
			return (0);
		else
			result = 1;
		str++;
	}
	return (result);
}
