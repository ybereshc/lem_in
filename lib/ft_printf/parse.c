/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:35:29 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:35:37 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	push(char *src, int len, int8_t to_free)
{
	int		n;

	if ((n = BUFF_SIZE - g_p.i - len) < 0)
	{
		push(src, len += n, 0);
		write(g_p.fd, g_p.buff, BUFF_SIZE);
		g_p.i = 0;
		push(src + len, -n, 0);
	}
	else
	{
		ft_memcpy(g_p.buff + g_p.i, src, len);
		g_p.i += len;
		g_p.len += len;
	}
	if (to_free)
		free(src);
}

void	form(char *src, int len, int8_t to_free)
{
	*g_p.dest = ft_strfjoin(*g_p.dest, ft_strndup(src, len), 3);
	g_p.len += len;
	if (to_free)
		free(src);
}

void	str_format(char *format)
{
	char	*tmp;

	ft_bzero(&g_p, offsetof(t_parse, buff));
	while (1)
	{
		if (!(tmp = ft_strchr(format, '%')))
			break ;
		g_func(format, tmp - format, 0);
		format = match(tmp + 1);
	}
	if (*format)
		g_func(format, ft_strlen(format), 0);
}
