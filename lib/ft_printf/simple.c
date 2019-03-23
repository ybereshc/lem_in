/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:34:24 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:34:28 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"

void	get_string(void)
{
	char	*res;

	if (!(res = va_arg(g_ap, char*)))
	{
		if (g_w.flag & to_free)
			g_w.flag ^= to_free;
		res = NULL_POINTER;
	}
	g_w.len = (g_w.prec) ? ft_strlen(res) : 0;
	g_w.len = (g_w.prec > 0 && g_w.len > g_w.prec) ? g_w.prec : g_w.len;
	g_w.res = ft_memcpy(ft_mlc(SIZE(char, g_w.len + 1)), res, g_w.len);
	g_w.res[g_w.len] = '\0';
	if (g_w.flag & to_free)
		free(res);
}

void	get_character(void)
{
	int	chr;

	if (!(chr = (g_w.type == 'c') ? va_arg(g_ap, int) : g_w.type))
	{
		g_w.res = ft_memalloc(SIZE(char, 2));
		g_w.len = 1;
	}
	else
	{
		g_w.res = (g_w.size == j) ? ft_unichr(chr) : ft_unichr((char)chr);
		g_w.len = ft_strlen(g_w.res);
	}
}

void	get_pointer(void)
{
	g_w.res = ft_uint_to_str((uintmax_t)va_arg(g_ap, void*), 16);
	g_w.len = ft_strlen(g_w.res);
	g_w.prefix = "0x";
	precision();
}
