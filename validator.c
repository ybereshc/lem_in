/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:35:03 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/21 18:35:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

extern t_room	*(*g_lem_parse_line)(char *line);

void	lem_cmd(char *cmd)
{
	char	*line;

	while ((line = lem_gnl()))
	{
		if (line[0] != '#')
			break ;
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			E(F("Wrong data format!"));
	}
	if (!line)
		E(F("Empty line!"));
	if (!ft_strcmp(cmd, "##start") && !g_l.start)
		g_l.start = g_lem_parse_line(line);
	else if (!ft_strcmp(cmd, "##end") && !g_l.end)
		g_l.end = g_lem_parse_line(line);
	return ;
}

void	lem_room_validator(t_room *new_room)
{
	size_t	i;
	t_room	*room;

	i = -1;
	while (++i < g_l.rooms->len - 1)
	{
		room = g_l.rooms->room[i];
		if (!(ft_strcmp(room->name, new_room->name)))
			E(F("Room name \"%s\" already exist!", new_room->name));
		if (room->pnt[0] == new_room->pnt[0] &&
		room->pnt[1] == new_room->pnt[1])
			E(F("Room \"%s\" duplicate coordinates!", new_room->name));
	}
}
