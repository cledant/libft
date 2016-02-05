/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char2_index_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:31:20 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:04:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_char2_index_size(char **argv)
{
	int		count;

	count = 0;
	while (argv != NULL && *argv != '\0')
	{
		count++;
		argv++;
	}
	return (count);
}
