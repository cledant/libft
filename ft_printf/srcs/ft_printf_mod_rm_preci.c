/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_mod_rm_preci.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 12:11:41 by cledant           #+#    #+#             */
/*   Updated: 2016/04/28 12:13:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_mod_rm_preci(char *s)
{
	char	*new;

	new = ft_strnew(1);
	ft_strdel(&s);
	return (new);
}
