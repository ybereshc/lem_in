/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:34:44 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 20:34:45 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	g_buff[256];
size_t	g_i;
size_t	g_size;
size_t	g_line;

static void	len_find_ln(char *buff)
{
	while (buff[g_i] && buff[g_i] != '\n')
		g_i++;
	buff[g_i] = 0;
}

char		*lem_gnl(void)
{
	size_t	n;
	char	*res;

	res = 0;
	if (++g_i < g_size)
	{
		n = g_i;
		len_find_ln(g_buff);
		res = ft_strjoin(res, g_buff + n);
	}
	if (g_i >= g_size)
		while ((g_size = read(0, g_buff, 255)))
		{
			g_i = 0;
			g_buff[g_size] = 0;
			len_find_ln(g_buff);
			res = ft_strfjoin(res, g_buff, 1);
			if (g_i < g_size)
				break ;
		}
	res ? g_line++ : (g_line = 0);
	ft_array_push(g_l.map, res);
	return (res);
}

void		lem_error(char *msg)
{
	if (!(g_l.o & error_management))
		ft_dprintf(2, "ERROR\n");
	else if (g_line)
		ft_dprintf(2, "%s: Error line %D: %s\n", g_process.name, g_line, msg);
	else
		ft_dprintf(2, "%s: Error: %s\n", g_process.name, msg);
	free(msg);
	exit(0);
}

static void	len_statistic(void)
{
	ft_separator("\n");
	W(COLOR("3;94;1", "Statistic:\n"));
	W(COLOR("1", "    Ants:  %U\n"), g_l.ants_count);
	W(COLOR("1", "    Rooms: %U\n"), g_l.rooms->len);
	W(COLOR("1", "    Paths: %U\n"), g_l.paths->len);
	W(COLOR("1", "    Steps: %U"), g_l.efficiency);
	if (g_l.best_steps > 0)
		W(COLOR("1", " vs. %U"), g_l.best_steps);
	W("\n");
}

int			main(int argc, char **argv)
{
	FT_INIT(MLC_ERROR | MLC_EXIT);
	lem_options();
	lem_parse();
	if (!(g_l.o & quiet_mode))
	{
		ft_separator("\n");
		ft_print_strary(g_l.map->line);
	}
	lem_deadlocks();
	lem_full_bfs();
	lem_tunnels();
	if (g_l.o & show_rooms)
		print_rooms();
	lem_path();
	if (g_l.efficiency == 1)
		lem_start_end_case();
	else
		lem_ants_creator();
	if (g_l.o & show_statistic)
		len_statistic();
	ft_free_strary(g_l.map->line);
	return (0);
}
