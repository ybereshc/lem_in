/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:36:25 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:36:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../libft.h"
# include "match.h"

# define BUFF_SIZE 512

typedef struct	s_parse
{
	ssize_t	len;
	int		i;
	char	buff[BUFF_SIZE];
	int		fd;
	char	**dest;
}				t_parse;

t_parse	g_p;
va_list	g_ap;
void	(*g_func)(char*, int, int8_t);

void			str_format(char *format);
void			push(char *src, int len, int8_t to_free);
void			form(char *src, int len, int8_t to_free);
char			*match(char *str);

#endif
