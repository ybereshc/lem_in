/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 18:56:57 by ybereshc          #+#    #+#             */
/*   Updated: 2019/01/26 18:56:58 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lib/libft.h"
# include "options.h"

# define E lem_error
# define RT room_type

typedef struct s_room	t_room;
typedef struct s_lemin	t_lemin;
typedef struct s_ant	t_ant;
typedef enum e_mark		t_mark;

typedef struct s_rooms	t_rooms;
typedef struct s_paths	t_paths;
typedef struct s_ants	t_ants;
typedef struct s_map	t_map;

struct	s_rooms
{
	t_room	**room;
	size_t	len;
	size_t	max;
};

struct	s_map
{
	char	**line;
	size_t	len;
	size_t	max;
};

struct	s_paths
{
	t_rooms	**path;
	size_t	len;
	size_t	max;
};

struct	s_ants
{
	t_ant	**ant;
	size_t	len;
	size_t	max;
};

struct	s_ant
{
	char	*name;
	t_room	*room;
};

enum	e_mark
{
	start = 1 << 0,
	end = 1 << 1,
	closed = 1 << 2,
	deadlock = 1 << 3,
	tunnel = 1 << 4,
	reserved = 1 << 5,
};

struct	s_room
{
	t_mark	mark;
	char	*name;
	int		pnt[2];
	t_rooms	*links;
	t_rooms	*crossroad;
	int		visit;
	t_room	*parent;
	char	*ant;
};

struct	s_lemin
{
	t_option	o;
	char		*ant_name;
	t_rooms		*rooms;
	t_room		*start;
	t_room		*end;
	size_t		ants_count;
	size_t		best_steps;
	t_paths		*paths;
	size_t		efficiency;
	t_ants		*ants;
	t_map		*map;
};

t_lemin		g_l;

char	*lem_gnl(void);
void	lem_error(char *msg);

t_room	*lem_find_room(char *name);
t_room	*lem_get_link(char *str);
t_room	*lem_get_room(char *str);
t_room	*lem_get_ant(char *str);
void	lem_parse(void);

void	lem_cmd(char *cmd);
void	lem_room_validator(t_room *new_room);

void	lem_deadlocks(void);
void	lem_full_bfs(void);
void	lem_tunnels(void);

void	lem_path(void);

void	lem_start_end_case(void);
void	lem_ants_creator(void);

char	*room_type(t_room *room);
void	print_room(t_room *room);
void	print_rooms(void);
void	print_path(t_rooms *path);
void	print_paths(void);

#endif
