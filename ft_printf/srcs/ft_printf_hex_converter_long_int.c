/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 10:14:16 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 17:16:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_len_hex(unsigned long int n)
{
	size_t			len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static void			ft_conv_hex(unsigned long int n, char *ret, size_t len)
{
	unsigned long int	cpy_n;

	cpy_n = n;
	while (cpy_n != 0)
	{
		cpy_n = cpy_n % 16;
		if (cpy_n > 9)
			ret[len - 1] = cpy_n - 10 + 'a';
		else
			ret[len - 1] = cpy_n + '0';
		n = n / 16;
		cpy_n = n;
		len--;
	}
}

char				*ft_printf_hex_converter_long_int(unsigned long int n)
{
	char	*ret;
	size_t	len;

	len = ft_len_hex(n);
	if (n == 0)
	{
		if ((ret = ft_strnew(1)) == NULL)
			return (NULL);
		ret[0] = '0';
		return (ret);
	}
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ft_conv_hex(n, ret, len);
	return (ret);
}
