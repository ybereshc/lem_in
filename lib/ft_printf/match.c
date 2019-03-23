/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:38:59 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:39:01 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "match.h"

static int	size(char *str, char *tmp)
{
	t_size	s;

	if (str[0] == 'h')
		s = (str[1] == 'h') ? hh : h;
	else if (str[0] == 'l')
		s = (str[1] == 'l') ? ll : l;
	else
		s = tmp - SIZES + 3;
	if (g_w.size < s)
		g_w.size = s;
	return ((s == hh || s == ll) ? 1 : 0);
}

static int	number(int *dest, char *str)
{
	int	i;

	if (*str == '*')
	{
		if ((*dest = va_arg(g_ap, int)) < 0)
			*dest = 0;
		return (0);
	}
	i = 0;
	*dest = 0;
	while (*str >= '0' && *str <= '9')
	{
		*dest = *dest * 10 + (*str++ - '0');
		i++;
	}
	return (i - 1);
}

static char	*flag(char *str)
{
	char	*tmp;

	while (*str)
	{
		if ((tmp = ft_strchr(FLAGS, *str)))
			g_w.flag |= ft_pow(2, tmp - FLAGS);
		else if ((tmp = ft_strchr(SIZES, *str)))
			str += size(str, tmp);
		else if (ft_strchr("123456789*", *str))
			str += number(&g_w.width, str);
		else if (*str == '.')
			str += number(&g_w.prec, str + 1);
		else
			break ;
		str++;
	}
	return (str);
}

char		*match(char *str)
{
	ft_bzero(&g_w, sizeof(t_print));
	g_w.prec = -1;
	str = flag(str);
	if (!(g_w.type = *str))
		return (str);
	if (g_w.type >= 'A' && g_w.type <= 'Z')
	{
		g_w.size = j;
		g_w.type += 32;
	}
	if (g_w.type == 's')
		get_string();
	else if (g_w.type == 'p')
		get_pointer();
	else if (ft_strchr("diuoxb", g_w.type))
		get_number();
	else
		get_character();
	width();
	g_func(g_w.res, g_w.len, 1);
	return (str + 1);
}
