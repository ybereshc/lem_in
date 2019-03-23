/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:31:02 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:31:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"

static uintmax_t	di_size(void)
{
	if (g_w.size)
	{
		if (g_w.size == hh)
			return ((char)va_arg(g_ap, int));
		if (g_w.size == h)
			return ((short)va_arg(g_ap, int));
		if (g_w.size == l)
			return (va_arg(g_ap, long int));
		if (g_w.size == ll)
			return (va_arg(g_ap, long long int));
		if (g_w.size == j)
			return (va_arg(g_ap, intmax_t));
		if (g_w.size == z)
			return (va_arg(g_ap, ssize_t));
	}
	return (va_arg(g_ap, int));
}

static uintmax_t	size(void)
{
	if (ft_strchr("di", g_w.type))
		return (di_size());
	if (g_w.size)
	{
		if (g_w.size == hh)
			return ((unsigned char)va_arg(g_ap, unsigned int));
		if (g_w.size == h)
			return ((unsigned short)va_arg(g_ap, unsigned int));
		if (g_w.size == l)
			return (va_arg(g_ap, unsigned long int));
		if (g_w.size == ll)
			return (va_arg(g_ap, unsigned long long int));
		if (g_w.size == j)
			return (va_arg(g_ap, uintmax_t));
		if (g_w.size == z)
			return (va_arg(g_ap, size_t));
	}
	return (va_arg(g_ap, unsigned int));
}

static uint8_t		base(void)
{
	if (g_w.type == 'b')
		return (2);
	if (g_w.type == 'o')
		return (8);
	if (g_w.type == 'x')
		return (16);
	return (10);
}

static char			*set_prefix(void)
{
	if (ft_strchr("di", g_w.type))
	{
		if (g_w.flag & plus)
			return ("+");
		if (g_w.flag & space)
			return (" ");
	}
	else if (g_w.flag & hash)
	{
		if (g_w.type == 'o')
			return ("0");
		if (g_w.type == 'x')
			return ("0x");
	}
	return (0);
}

void				get_number(void)
{
	uintmax_t	val;

	val = size();
	if (ft_strchr("di", g_w.type))
	{
		if ((intmax_t)val < 0)
		{
			val = -val;
			g_w.prefix = "-";
		}
	}
	if (!g_w.prefix)
		g_w.prefix = set_prefix();
	g_w.res = ft_uint_to_str(val, base());
	g_w.len = ft_strlen(g_w.res);
	if (g_w.flag & split && ft_strchr("di", g_w.type))
	{
		g_w.prec = -1;
		if (g_w.flag & zero)
			g_w.flag ^= zero;
		number_split();
	}
	precision();
}
