/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_not_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:36:48 by cledant           #+#    #+#             */
/*   Updated: 2016/05/17 11:46:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	ft_length_nb(int nb)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int						ft_is_not_int(char *str)
{
	size_t		len_str;
	size_t		len_nb;

	len_nb = ft_length_nb(ft_atoi(str));
	len_str = ft_can_be_atoi_len(str);
	if (len_nb == len_str)
		return (0);
	else
		return (1);
}
