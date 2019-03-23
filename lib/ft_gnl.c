/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:33 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"
#include "libft.h"

t_gnl		*g_head;
t_gnl_res	g_r;

static int8_t	gnl_fd(int fd, int8_t delete)
{
	t_gnl **gnl;
	t_gnl *tmp;

	if (!delete && !read(fd, 0, 0))
		return (1);
	gnl = &g_head;
	while (*gnl)
	{
		if ((*gnl)->fd == fd)
		{
			tmp = *gnl;
			*gnl = (*gnl)->next;
			free(tmp);
			break ;
		}
		gnl = &(*gnl)->next;
	}
	return (0);
}

static t_gnl	*get_gnl(int fd, int8_t create)
{
	t_gnl	*gnl;

	gnl = g_head;
	if (!gnl || create)
	{
		if (!(gnl = ft_memalloc(sizeof(t_gnl))))
			return (0);
		gnl->fd = fd;
		return (gnl);
	}
	while (gnl)
	{
		if (gnl->fd == fd)
			return (gnl);
		if (!gnl->next)
			return (gnl->next = get_gnl(fd, 1));
		gnl = gnl->next;
	}
	return (0);
}

static int8_t	gnl_join(void)
{
	ssize_t	i;
	ssize_t	size;
	char	*tmp;

	i = g_r.gnl->i;
	while (g_r.gnl->i < g_r.gnl->size && g_r.gnl->buff[g_r.gnl->i] != '\n')
		g_r.gnl->i++;
	size = g_r.gnl->i - i + g_r.len;
	if (!(tmp = ft_mlc(sizeof(char) * (size + 1))))
		return (0);
	tmp[size] = '\0';
	ft_memcpy(tmp, g_r.ptr, g_r.len);
	free(g_r.ptr);
	ft_memcpy(tmp + g_r.len, g_r.gnl->buff + i, g_r.gnl->i - i);
	g_r.ptr = tmp;
	g_r.len = size;
	return (1);
}

ssize_t			ft_gnl(int fd, char **line)
{
	ft_bzero(&g_r, sizeof(t_gnl_res));
	if (fd < 0 || !line || !gnl_fd(fd, 0) || !(g_r.gnl = get_gnl(fd, 0)))
		return (ERROR(-1));
	if (!g_head)
		g_head = g_r.gnl;
	if (g_r.gnl->i < g_r.gnl->size && ++g_r.gnl->i)
		if (!(gnl_join()))
			return (ERROR(-1));
	if (g_r.gnl->i >= g_r.gnl->size)
	{
		while ((g_r.gnl->size = read(g_r.gnl->fd, g_r.gnl->buff, BUFF_SIZE)))
		{
			g_r.gnl->i = 0;
			if (g_r.gnl->size < 0 || !gnl_join())
				return (ERROR(-1));
			if (g_r.gnl->i < g_r.gnl->size)
				break ;
		}
	}
	if (!g_r.gnl->size && !g_r.len)
		return (ERROR((ssize_t)ft_free(1, g_r.ptr)));
	*line = g_r.ptr;
	return (g_r.len);
}
