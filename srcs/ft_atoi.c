/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:27:12 by cledant           #+#    #+#             */
/*   Updated: 2016/02/02 09:45:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ten_pow(int power)
{
	int counter;
	int result;

	result = 1;
	counter = 0;
	if (power == 0)
		return (result);
	else
	{
		while (counter < power)
		{
			result = result * 10;
			counter++;
		}
		return (result);
	}
}

static size_t	ft_strlen_digit(const char *str)
{
	size_t	len;

	len = 0;
	if (*str == '+' || *str == '-' || (*str >= 48 && *str <= 57))
	{
		len++;
		str++;
	}
	while (*str != '\0' && (*str >= 48 && *str <= 57))
	{
		str++;
		len++;
	}
	return (len);
}

static int		ft_internal_atoi(const char *s, int count, int s_len, int res)
{
	while (count < s_len)
	{
		if (*s == '+')
			return (res);
		if (*s == '-')
		{
			res = -res;
			return (res);
		}
		if (*s != '+' || *s != '-')
		{
			res = res + ft_ten_pow(count) * (*s - 48);
			s--;
			count++;
			if (count > 11)
				return (0);
			ft_internal_atoi(s, count, s_len, res);
		}
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	int			result;
	size_t		counter;
	size_t		str_len;

	counter = 0;
	result = 0;
	while (*str == ft_isspace(*str) || (*str >= 9 && *str <= 13))
		str++;
	str_len = ft_strlen_digit(str);
	str = str + str_len - 1;
	result = ft_internal_atoi(str, counter, str_len, result);
	return (result);
}
