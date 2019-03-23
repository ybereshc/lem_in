/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:40:50 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:40:55 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATCH_H
# define MATCH_H

# include "../libft.h"
# include "parse.h"

# define FLAGS "-+ #0,^"
# define SIZES "hljz"
# define NULL_POINTER "(null)"

typedef	enum	e_flags
{
	minus = 1,
	plus = 2,
	space = 4,
	hash = 8,
	zero = 16,
	split = 32,
	to_free = 64,
}				t_flags;

typedef	enum	e_size
{
	hh = 1,
	h = 2,
	l = 3,
	ll = 4,
	j = 5,
	z = 6,
}				t_size;

typedef struct	s_print
{
	t_flags	flag;
	t_size	size;
	char	type;
	char	*prefix;
	char	*res;
	int		len;
	int		width;
	int		prec;
}				t_print;

t_print	g_w;

void			push(char *src, int len, int8_t to_free);

void			get_string(void);
void			get_character(void);
void			get_pointer(void);
void			get_number(void);

void			precision(void);
void			width(void);
void			number_split(void);

#endif
