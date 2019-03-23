/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assoc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:29 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:31 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASSOC_H
# define FT_ASSOC_H

typedef struct	s_assoc
{
	char	**key;
	void	**ptr;
	int		len;
	int		max;
}				t_assoc;

#endif
