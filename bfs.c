/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/26 18:56:58 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int8_t	lem_queue(t_rooms *queue, t_room *room, int visit)
{
	size_t	i;
	t_room	*link;

	i = -1;
	while (++i < room->crossroad->len)
	{
		link = room->crossroad->room[i];
		if (link->mark & (end | closed) || link->visit == visit)
			continue;
		link->parent = room;
		if (link->mark & start)
			return (1);
		link->visit = visit;
		ft_array_push(queue, link);
	}
	return (0);
}

static int8_t	lem_bfs(void)
{
	static int	bfs = 1;
	size_t		i;
	t_rooms		*queue;

	bfs++;
	lem_queue((queue = ft_array(g_l.rooms->len)), g_l.end, bfs);
	i = -1;
	while (++i < queue->len)
		if (lem_queue(queue, queue->room[i], bfs))
			break ;
	ft_array_free(queue);
	if (g_l.start->parent)
		return (1);
	return (0);
}

static size_t	paths_efficiency(void)
{
	size_t	i;
	size_t	steps;
	size_t	ants;

	ants = 0;
	steps = 0;
	while (ants < g_l.ants_count)
	{
		steps++;
		i = -1;
		while (++i < g_l.paths->len)
			if (g_l.paths->path[i]->len - 2 < steps)
				ants++;
	}
	return (steps);
}

static int8_t	save_path(void)
{
	t_room	*room;
	t_rooms	*path;

	path = ft_array(1);
	room = g_l.start;
	while (room)
	{
		ft_array_push(path, room);
		if (!(room->mark & (start | end)))
			room->mark |= closed;
		room = room->parent;
	}
	g_l.start->parent = 0;
	ft_array_push(g_l.paths, path);
	if (path->room[1]->mark & end)
		return (1);
	return (0);
}

void			lem_path(void)
{
	size_t	efficiency;

	g_l.efficiency = -1;
	g_l.paths = ft_array(1);
	while (lem_bfs())
	{
		if (save_path())
		{
			g_l.efficiency = 1;
			break ;
		}
		if (g_l.efficiency > (efficiency = paths_efficiency()))
			g_l.efficiency = efficiency;
		else
		{
			g_l.paths->len--;
			break ;
		}
	}
	if (g_l.o & show_paths)
		print_paths();
}
