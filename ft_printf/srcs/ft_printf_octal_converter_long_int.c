/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal_converter.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 09:33:40 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 16:36:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		ft_len_octal(unsigned long int n)
{
	size_t			len;

	len = 0;
	while (n != 0)
	{
		n = n / 8;
		len++;
	}
	return (len);
}

static void			ft_conv_octal(unsigned long int n, char *ret, size_t len)
{
	unsigned long int	cpy_n;

	cpy_n = n;
	while (cpy_n != 0)
	{
		cpy_n = cpy_n % 8;
		ret[len - 1] = cpy_n + '0';
		n = n / 8;
		cpy_n = n;
		len--;
	}
}

char				*ft_printf_octal_converter_long_int(unsigned long int n)
{
	char	*ret;
	size_t	len;

	len = ft_len_octal(n);
	if (n == 0)
	{
		if ((ret = ft_strnew(1)) == NULL)
			return (NULL);
		ret[0] = '0';
		return (ret);
	}
	if ((ret = ft_strnew(len)) == NULL)
		return (NULL);
	ft_conv_octal(n, ret, len);
	return (ret);
}
