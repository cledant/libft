/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab2_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 08:54:07 by cledant           #+#    #+#             */
/*   Updated: 2015/12/19 16:40:15 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_int_tab2_new(size_t i, size_t j)
{
	int		**tab;
	int		**cpy_tab;
	size_t	counter_i;

	counter_i = 0;
	tab = (int **)malloc(sizeof(int *) * j);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, sizeof(int *) * j);
	cpy_tab = tab;
	while (counter_i < j)
	{
		*tab = (int *)malloc(sizeof(int) * i);
		if (*tab == NULL)
			return (cpy_tab);
		ft_bzero(*tab, sizeof(int) * i);
		tab++;
		counter_i++;
	}
	return (cpy_tab);
}
