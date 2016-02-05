/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 09:04:12 by cledant           #+#    #+#             */
/*   Updated: 2016/01/04 09:04:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_round_double(double nb)
{
	int		nb_int;

	nb_int = (int)nb;
	if (ft_abs(nb_int - nb) >= 0.5)
		nb_int++;
	return (nb_int);
}
