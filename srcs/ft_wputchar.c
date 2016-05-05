/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 20:03:42 by cledant           #+#    #+#             */
/*   Updated: 2016/05/05 10:14:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_size_2(wchar_t c)
{
	unsigned int	tab[4];
	unsigned int	part[2];

	ft_bzero(part, sizeof(int) * 2);
	tab[0] = 63;
	tab[1] = 1984;
	tab[2] = 128;
	tab[3] = 49152;
	part[0] = tab[0] & (unsigned int)c;
	part[1] = tab[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[0] = tab[2] | part[0];
	part[1] = tab[3] | part[1];
	part[1] = part[1] >> 8;
	write(1, &part[1], 1);
	write(1, &part[0], 1);
}

static void	ft_print_size_4(wchar_t c, unsigned int *tab)
{
	unsigned int	part[4];

	ft_bzero(part, sizeof(int) * 4);
	part[0] = tab[0] & (unsigned int)c;
	part[1] = tab[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[2] = tab[2] & (unsigned int)c;
	part[2] = part[2] << 4;
	part[3] = tab[3] & (unsigned int)c;
	part[3] = part[3] << 6;
	part[0] = tab[4] | part[0];
	part[1] = tab[5] | part[1];
	part[1] = part[1] >> 8;
	part[2] = tab[6] | part[2];
	part[2] = part[2] >> 16;
	part[3] = tab[7] | part[3];
	part[3] = part[3] >> 24;
	write(1, &part[3], 1);
	write(1, &part[2], 1);
	write(1, &part[1], 1);
	write(1, &part[0], 1);
}

static void	ft_size_4(wchar_t c)
{
	unsigned int	tab[8];

	tab[0] = 63;
	tab[1] = 4032;
	tab[2] = 258048;
	tab[3] = 1835008;
	tab[4] = 128;
	tab[5] = 32768;
	tab[6] = 8388608;
	tab[7] = 4026531840;
	ft_print_size_4(c, tab);
}

static void	ft_size_3(wchar_t c)
{
	unsigned int	tab[8];
	unsigned int	part[4];

	ft_bzero(part, sizeof(int) * 3);
	tab[0] = 63;
	tab[1] = 4032;
	tab[2] = 61440;
	tab[3] = 128;
	tab[4] = 32768;
	tab[5] = 14680064;
	part[0] = tab[0] & (unsigned int)c;
	part[1] = tab[1] & (unsigned int)c;
	part[1] = part[1] << 2;
	part[2] = tab[2] & (unsigned int)c;
	part[2] = part[2] << 4;
	part[0] = tab[3] | part[0];
	part[1] = tab[4] | part[1];
	part[1] = part[1] >> 8;
	part[2] = tab[5] | part[2];
	part[2] = part[2] >> 16;
	write(1, &part[2], 1);
	write(1, &part[1], 1);
	write(1, &part[0], 1);
}

void		ft_wputchar(wchar_t c)
{
	size_t			size;

	size = ft_wcharlen(c);
	if (size == 1)
		write(1, &c, 1);
	else if (size == 2)
		ft_size_2(c);
	else if (size == 3)
		ft_size_3(c);
	else if (size == 4)
		ft_size_4(c);
}
