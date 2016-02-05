/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 10:11:28 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:57:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn(char const *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		ft_putchar(*s);
		counter++;
		s++;
	}
}
