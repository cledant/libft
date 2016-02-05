/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_char2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 09:48:10 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:13:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel_char2(char ***argv)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_char2_index_size(*argv);
	while (i < size)
	{
		free(argv[0][i]);
		argv[0][i] = NULL;
		i++;
	}
	free(argv[0]);
	argv[0] = NULL;
}
