/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/26 18:56:58 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	kill_deadlocks(t_room *room)
{
	t_room	*link;
	size_t	i;
	size_t	j;
	int		n;

	if (room->mark & (deadlock | start | end))
		return ;
	room->mark |= deadlock;
	n = 0;
	i = -1;
	while (++i < room->links->len)
	{
		link = room->links->room[i];
		j = -1;
		while (++j < link->links->len)
			if (!(link->links->room[j]->mark & deadlock))
				n++;
		if (n < 2)
			kill_deadlocks(link);
	}
}

void		lem_deadlocks(void)
{
	size_t	i;
	t_room	*room;

	i = -1;
	while (++i < g_l.rooms->len && (room = g_l.rooms->room[i]))
		if (room->links->len < 2)
			if (!(room->mark & (deadlock | start | end)))
				kill_deadlocks(room);
}

static void	lem_full_queue(t_rooms *queue, t_room *room, int visit)
{
	size_t	i;
	t_room	*link;

	i = -1;
	while (++i < room->links->len)
	{
		link = room->links->room[i];
		if (link->mark & (deadlock | start))
			continue;
		if (link->visit != visit)
			ft_array_push(queue, link);
		link->visit = visit;
		if (!link->crossroad)
			link->crossroad = ft_array(room->links->len);
		ft_array_push(link->crossroad, room);
	}
}

void		lem_full_bfs(void)
{
	size_t	i;
	t_rooms	*queue;

	lem_full_queue((queue = ft_array(g_l.rooms->len)), g_l.start, 1);
	i = -1;
	while (++i < queue->len)
		lem_full_queue(queue, queue->room[i], 1);
	ft_array_free(queue);
	if (!g_l.end->crossroad)
		E(F("Can't build a path!"));
}

void		lem_tunnels(void)
{
	size_t	i;
	t_room	*room;

	i = -1;
	while (++i < g_l.rooms->len && (room = g_l.rooms->room[i]))
		if (!(room->mark & (start | end)))
			if (room->crossroad && room->crossroad->len < 3)
				room->mark |= tunnel;
}
