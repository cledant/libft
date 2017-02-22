/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:23:58 by cledant           #+#    #+#             */
/*   Updated: 2016/04/22 13:49:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlenitoi(unsigned long int n)
{
	size_t	result;

	result = 1;
	while (n / 10 > 0)
	{
		result++;
		n = n / 10;
	}
	return (result);
}

static char		*ft_internal_itoa(unsigned long int n, size_t len, char *res)
{
	char *cpy_res;

	cpy_res = res;
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

char			*ft_printf_itoa_unsigned_long_int(unsigned long int n)
{
	size_t	len;
	char	*result;

	len = ft_strlenitoi(n);
	result = ft_strnew(len);
	if (result == NULL)
		return (result);
	result = ft_internal_itoa(n, len, result);
	return (result);
}
