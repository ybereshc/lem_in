/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   march.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:41:43 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/13 17:41:44 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		len_ant_direction(size_t *a)
{
	size_t			i;
	size_t			j;
	size_t			len;
	t_ant			*ant;

	if (*a == g_l.ants_count)
		return ;
	i = -1;
	while (++i < g_l.paths->len)
	{
		len = 0;
		j = -1;
		while (++j < i)
			len += (g_l.paths->path[i]->len - g_l.paths->path[j]->len);
		if (g_l.ants_count - *a > len)
		{
			(*a)++;
			ant = ft_array_push(g_l.ants, ft_memalloc(sizeof(t_ant)));
			ant->name = F("%s%d", g_l.ant_name, *a);
			ant->room = g_l.paths->path[i]->room[1];
		}
		if (*a == g_l.ants_count)
			return ;
	}
}

static int8_t	len_move_ants(void)
{
	size_t	i;
	size_t	j;
	int8_t	move;
	t_rooms	*path;

	move = 0;
	i = -1;
	while (++i < g_l.paths->len)
	{
		path = g_l.paths->path[i];
		j = path->len - 1;
		while (j--)
		{
			if (path->room[j]->ant)
			{
				move = 1;
				path->room[j + 1]->ant = path->room[j]->ant;
				path->room[j]->ant = 0;
				W("%s-%s ", path->room[j + 1]->ant, path->room[j + 1]->name);
			}
		}
	}
	return (move);
}

void			lem_start_end_case(void)
{
	size_t	i;

	ft_separator("\n");
	i = 0;
	while (++i <= g_l.ants_count)
		W("%s%d-%s ", g_l.ant_name, i, g_l.end->name);
	W("\n");
}

void			lem_ants_creator(void)
{
	size_t	i;
	size_t	p;
	t_ant	*ant;
	int8_t	move;

	ft_separator("\n");
	g_l.ants = ft_array(g_l.ants_count);
	p = 0;
	while (p < g_l.ants_count)
		len_ant_direction(&p);
	i = 0;
	while (i < g_l.ants_count || move)
	{
		move = len_move_ants();
		p = -1;
		while (i < g_l.ants_count && ++p < g_l.paths->len &&
			!g_l.ants->ant[i]->room->ant)
		{
			ant = g_l.ants->ant[i++];
			ant->room->ant = ant->name;
			move = !!W("%s-%s ", ant->name, ant->room->name);
		}
		if (i < g_l.ants_count || move)
			W("\n");
	}
}
