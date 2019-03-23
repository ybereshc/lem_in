/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:04:27 by ybereshc          #+#    #+#             */
/*   Updated: 2018/11/24 19:04:38 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <unistd.h>

typedef struct s_el		t_el;
typedef struct s_list	t_list;

struct	s_el
{
	void	*ptr;
	t_el	*next;
};

struct	s_list
{
	t_el	*head;
	t_el	*last;
	size_t	count;
};

#endif
