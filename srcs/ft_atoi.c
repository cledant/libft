/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:27:12 by cledant           #+#    #+#             */
/*   Updated: 2016/05/17 11:39:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int				ft_ten_pow(int power)
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

static inline size_t			ft_strlen_digit(const char *str)
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

static inline long long int		ft_internal_atoi(const char *s, int count,
									int s_len, long long int res)
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

int								ft_atoi(const char *str)
{
	long long int		result;
	size_t				counter;
	size_t				str_len;

	counter = 0;
	result = 0;
	while (ft_isspace(*str) == 1)
		str++;
	str_len = ft_strlen_digit(str);
	str = str + str_len - 1;
	result = ft_internal_atoi(str, counter, str_len, result);
	if (result > 2147483647)
		return (0);
	if (result < -2147483648)
		return (0);
	return (result);
}
