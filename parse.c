/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:35:03 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/21 18:35:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*(*g_lem_parse_line)(char *line) = &lem_get_ant;

t_room	*lem_find_room(char *name)
{
	size_t	i;

	i = -1;
	while (++i < g_l.rooms->len)
		if (!ft_strcmp(g_l.rooms->room[i]->name, name))
			return (g_l.rooms->room[i]);
	E(F("Can't find room \"%s\"!", name));
	return (0);
}

t_room	*lem_get_link(char *str)
{
	char	**split;
	t_room	*r1;
	t_room	*r2;

	if (ft_strchr(str, ' ') || ft_strchrcount(str, '-') != 1)
		E(F("Wrong data format!"));
	split = ft_strsplit(str, '-');
	r1 = lem_find_room(split[0]);
	r2 = lem_find_room(split[1]);
	ft_array_push(r1->links, r2);
	ft_array_push(r2->links, r1);
	ft_free_strary(split);
	return (0);
}

t_room	*lem_get_room(char *str)
{
	t_room	*room;
	char	**split;

	if (ft_strchrcount(str, ' ') != 2)
	{
		g_lem_parse_line = &lem_get_link;
		return (lem_get_link(str));
	}
	if (str[0] == 'L')
		E(F("Room name can't start with the character L!"));
	room = ft_array_push(g_l.rooms, ft_memalloc(sizeof(t_room)));
	split = ft_strsplit(str, ' ');
	room->name = ft_strdup(split[0]);
	if (!ft_isnumeric(split[1]) || !ft_isnumeric(split[2]))
		E(F("Invalid room coordinates!"));
	room->pnt[0] = ft_atoi(split[1]);
	room->pnt[1] = ft_atoi(split[2]);
	room->links = ft_array(1);
	ft_free_strary(split);
	lem_room_validator(room);
	return (room);
}

t_room	*lem_get_ant(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	g_l.ants_count = ft_atoi(str);
	if (str[0] == '-' || len != ft_intlen(g_l.ants_count) || g_l.ants_count < 1
		|| g_l.ants_count > INT_MAX)
		E(F("Wrong number of ants!"));
	g_lem_parse_line = &lem_get_room;
	return (0);
}

void	lem_parse(void)
{
	char	*line;

	g_l.rooms = ft_array(42);
	g_l.map = ft_array(42);
	while ((line = lem_gnl()))
	{
		if (!*line)
			E(F("Empty line!"));
		if (line[0] == '#')
		{
			if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
				lem_cmd(line);
			else if (!ft_strncmp(line, "#Here is the number of lines", 28))
				g_l.best_steps = ft_atoi(line + 39);
		}
		else
			g_lem_parse_line(line);
	}
	if (!g_l.start)
		E(F("Start room wasn't detected!"));
	if (!g_l.end)
		E(F("End room wasn't detected!"));
	g_l.start->mark = start;
	g_l.end->mark = end;
}
