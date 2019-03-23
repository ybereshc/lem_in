/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:44:20 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 17:44:22 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "options.h"
#include "lem_in.h"

char	*g_usage = "\
usage: %s [--help] [-q|--quite] [-e|--error] [-r|--show-rooms] \
[-p|--show-path] [-R|--show-all-rooms] [-s|--statistic]\n\
";

char	*g_help = "\n\
The commands that you can use in the %s:\n    \
help              Show this message\n    \
quite             Silent mode\n    \
error             Error management\n    \
statistic         Show statistic\n    \
show-paths        Show all found paths\n    \
show-rooms        Show rooms data\n    \
show-all-rooms    Show all rooms data\n\
";

static void	options_error(int err)
{
	if (err & 1)
		ft_dprintf(2, g_usage, g_process.name);
	if (err & 2)
		ft_dprintf(2, g_help, g_process.name);
	exit(0);
}

static void	get_options(char *option)
{
	if (!option || !*option)
		options_error(1);
	else if (!ft_strcmp("help", option))
		options_error(3);
	else if (!ft_strcmp("quite", option))
		g_l.o |= quiet_mode;
	else if (!ft_strcmp("show-rooms", option))
		g_l.o |= show_rooms;
	else if (!ft_strcmp("show-paths", option))
		g_l.o |= show_paths;
	else if (!ft_strcmp("show-all-rooms", option))
		g_l.o |= show_all_rooms;
	else if (!ft_strcmp("error", option))
		g_l.o |= error_management;
	else if (!ft_strcmp("statistic", option))
		g_l.o |= show_statistic;
	else
	{
		ft_dprintf(2, "%s: illegal option -- %s\n", g_process.name, option);
		options_error(1);
	}
}

static void	get_flags(char *flags)
{
	char	*f;

	if (!flags || !*flags)
		options_error(1);
	else if (flags[0] == '-')
		return (get_options(flags + 1));
	while (*flags)
	{
		if ((f = ft_strchr(FLAGS, *flags)))
			g_l.o |= ft_upow(2, (uintmax_t)(f - FLAGS));
		else
		{
			ft_dprintf(2, "%s: illegal option -- %c\n", g_process.name, *flags);
			options_error(1);
		}
		flags++;
	}
}

void		lem_options(void)
{
	int	i;

	g_l.ant_name = "L";
	i = -1;
	while (++i < g_process.argc)
	{
		if (g_process.argv[i][0] == '-')
			get_flags(g_process.argv[i] + 1);
		else
			options_error(1);
	}
	if (g_l.o & show_all_rooms)
		g_l.o |= show_rooms;
}
