/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2_index_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:31:20 by cledant           #+#    #+#             */
/*   Updated: 2016/11/13 17:25:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_char2_index_size(char **argv)
{
	size_t	count;

	count = 0;
	while (argv != NULL && *argv != '\0')
	{
		count++;
		argv++;
	}
	return (count);
}
