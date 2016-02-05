/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_a_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 11:27:37 by cledant           #+#    #+#             */
/*   Updated: 2016/01/24 11:36:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_str_a_number(char *str)
{
	int		result;

	result = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		else
			result = 1;
		str++;
	}
	return (result);
}
