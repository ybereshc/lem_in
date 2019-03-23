/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:37:04 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:37:06 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"

static void	prefix(void)
{
	if (g_w.prefix)
	{
		g_w.res = ft_strfjoin(g_w.prefix, g_w.res, 2);
		g_w.len += ft_strlen(g_w.prefix);
	}
	g_w.prefix = 0;
}

void		precision(void)
{
	char	*tmp;
	char	c;

	if (g_w.prec <= g_w.len)
		return ;
	tmp = ft_mlc(SIZE(char, g_w.prec + 1));
	tmp[g_w.prec] = '\0';
	c = ft_strchr("uxdbo", g_w.type) ? '0' : ' ';
	ft_memset(tmp, c, g_w.prec - g_w.len);
	ft_memcpy(tmp + g_w.prec - g_w.len, g_w.res, g_w.len);
	free(g_w.res);
	g_w.res = tmp;
	g_w.len = g_w.prec;
}

void		width(void)
{
	char	*tmp;

	if (!(g_w.flag & zero))
		prefix();
	if (g_w.prefix)
		g_w.width -= ft_strlen(g_w.prefix);
	if (g_w.width <= g_w.len)
		return ;
	tmp = ft_mlc(SIZE(char, g_w.width + 1));
	tmp[g_w.width] = '\0';
	if (g_w.flag & minus)
	{
		ft_memcpy(tmp, g_w.res, g_w.len);
		ft_memset(tmp + g_w.len, ' ', g_w.width - g_w.len);
	}
	else
	{
		ft_memset(tmp, (g_w.flag & zero ? '0' : ' '), g_w.width - g_w.len);
		ft_memcpy(tmp + g_w.width - g_w.len, g_w.res, g_w.len);
	}
	free(g_w.res);
	g_w.res = tmp;
	g_w.len = g_w.width;
	prefix();
}

void		number_split(void)
{
	int		n;
	int		i;
	int		l;
	char	*tmp;

	l = g_w.len;
	if (!(n = l / 3 + ((l % 3) ? 0 : -1)))
		return ;
	n += l;
	g_w.len = n;
	tmp = ft_mlc(SIZE(char, n + 1));
	tmp[n] = '\0';
	i = 0;
	while (n-- > 0)
	{
		if (i && !(i % 3))
			tmp[n--] = ',';
		tmp[n] = g_w.res[--l];
		i++;
	}
	free(g_w.res);
	g_w.res = tmp;
}
