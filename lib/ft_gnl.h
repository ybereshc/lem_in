/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:33 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GNL_H
# define FT_GNL_H

# define BUFF_SIZE 4096
# define ERROR(e) ((ssize_t)(*line = 0) + e)
# include <unistd.h>

typedef struct	s_gnl
{
	int				fd;
	char			buff[BUFF_SIZE];
	ssize_t			i;
	ssize_t			size;
	struct s_gnl	*next;
}				t_gnl;

typedef struct	s_gnl_res
{
	t_gnl	*gnl;
	char	*ptr;
	ssize_t	len;
}				t_gnl_res;

#endif
