/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:50:03 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/23 19:50:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESS_H
# define FT_PROCESS_H

# include "libft.h"

# define FT_INIT(o) ft_init(argc, argv, (o))
# define MLC_ERROR 1
# define MLC_EXIT 2

typedef struct	s_process
{
	char		*name;
	char		**argv;
	int			argc;
	uintmax_t	options;
}				t_process;

t_process	g_process;

#endif
