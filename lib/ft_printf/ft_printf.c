/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:40:22 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:40:25 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

ssize_t		ft_printf(char *format, ...)
{
	if (!format || !*format)
		return (!format ? -1 : 0);
	g_p.fd = 1;
	g_func = &push;
	va_start(g_ap, format);
	str_format(format);
	va_end(g_ap);
	if (g_p.i)
		write(g_p.fd, g_p.buff, g_p.i);
	return (g_p.len);
}

ssize_t		ft_dprintf(int fd, char *format, ...)
{
	if (!format || !*format || fd < 0)
		return ((!format || fd < 0) ? -1 : 0);
	g_p.fd = fd;
	g_func = &push;
	va_start(g_ap, format);
	str_format(format);
	va_end(g_ap);
	if (g_p.i)
		write(g_p.fd, g_p.buff, g_p.i);
	return (g_p.len);
}

char		*ft_format(char *format, ...)
{
	char	*res;

	if (!format)
		return (0);
	res = 0;
	g_p.dest = &res;
	g_func = &form;
	va_start(g_ap, format);
	str_format(format);
	va_end(g_ap);
	return (res);
}

ssize_t		ft_sformat(char **dest, char *format, ...)
{
	if (!dest || !format)
		return (-1);
	*dest = 0;
	g_p.dest = dest;
	g_func = &form;
	va_start(g_ap, format);
	str_format(format);
	va_end(g_ap);
	return (g_p.len);
}
