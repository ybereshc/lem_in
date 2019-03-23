/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 20:34:45 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <limits.h>
#include "lem_in.h"

char	*room_type(t_room *room)
{
	char	*format;
	char	*color;

	if (room->mark & start)
		color = "\e[92m";
	else if (room->mark & end)
		color = "\e[91m";
	else if (room->mark & deadlock)
		color = "\e[90m";
	else if (room->mark & tunnel)
		color = "\e[93m";
	else
		color = "\e[97m";
	if (room->mark & (start | end))
		format = "%s{%s}\e[0m";
	else if (room->mark & tunnel)
		format = "%s|%s|\e[0m";
	else if (room->mark & deadlock)
		format = "%s(%s)\e[0m";
	else
		format = "%s[%s]\e[0m";
	return (F(format, color, room->name));
}

void	print_room(t_room *room)
{
	size_t	i;

	W("    Room:      %^s", RT(room));
	if (room->links && room->links->len)
	{
		W("\n    Links:    ");
		i = -1;
		while (++i < room->links->len)
			W(" %^s", RT(room->links->room[i]));
	}
	if (room->crossroad && room->crossroad->len)
	{
		W("\n    Crossroad:");
		i = -1;
		while (++i < room->crossroad->len)
			W(" %^s", RT(room->crossroad->room[i]));
	}
	W("\n");
}

void	print_rooms(void)
{
	t_room	*room;
	size_t	i;

	ft_separator("\n");
	W(COLOR("3;94;1", "Rooms: %U\n"), g_l.rooms->len);
	i = -1;
	while (++i < g_l.rooms->len)
	{
		room = g_l.rooms->room[i];
		if (g_l.o & show_all_rooms || !(room->mark & deadlock))
		{
			if (i)
				W("\n");
			print_room(room);
		}
	}
}

void	print_path(t_rooms *path)
{
	size_t	i;

	i = -1;
	W(COLOR("1", "    [Length: %U] "), path->len - 1);
	while (++i < path->len)
	{
		if (i)
			W(COLOR("90", "->"));
		W("%^s", RT(path->room[i]));
	}
	W("\n");
}

void	print_paths(void)
{
	size_t	i;

	ft_separator("\n");
	i = g_l.efficiency;
	W(COLOR("3;94;1", "Paths: %U Efficiency: %U\n"), g_l.paths->len, i);
	i = -1;
	while (++i < g_l.paths->len)
		print_path(g_l.paths->path[i]);
}
