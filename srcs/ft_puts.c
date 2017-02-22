/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:41:03 by cledant           #+#    #+#             */
/*   Updated: 2017/02/22 10:49:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puts(const char *s)
{
	size_t		len;

	if (s == NULL)
	{
		if (write(1, "(null)\n", 7) == -1)
			return (-1);
		return (10);
	}
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	if (write(1, "\n", 1) == -1)
		return (-1);
	return (10);
}
