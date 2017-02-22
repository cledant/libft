/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_long_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:38:57 by cledant           #+#    #+#             */
/*   Updated: 2016/05/03 20:16:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	ft_strlenitoi(long int n)
{
	size_t	result;

	result = 1;
	if (n < 0)
	{
		n = -n;
		result++;
	}
	while (n / 10 > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static char		*ft_internal_itoa(long int n, size_t len, char *res)
{
	char *cpy_res;

	cpy_res = res;
	if (n < 0)
	{
		n = -n;
		*res = '-';
		len--;
		res++;
	}
	res = res + len - 1;
	while (len != 0)
	{
		*res = n % 10 + '0';
		n = n / 10;
		res--;
		len--;
	}
	return (cpy_res);
}

char			*ft_printf_itoa_long_int(long int n)
{
	size_t	len;
	char	*result;

	len = ft_strlenitoi(n);
	if (n == LONG_MIN)
	{
		result = ft_strnew(20);
		return (ft_strcpy(result, "-9223372036854775808"));
	}
	result = ft_strnew(len);
	if (result == NULL)
		return (result);
	result = ft_internal_itoa(n, len, result);
	return (result);
}
