/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:44:25 by ybereshc          #+#    #+#             */
/*   Updated: 2019/03/10 17:44:26 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# define FLAGS "qprRes"

typedef enum e_option	t_option;

enum	e_option
{
	quiet_mode = 1 << 0,
	show_paths = 1 << 1,
	show_rooms = 1 << 2,
	show_all_rooms = 1 << 3,
	error_management = 1 << 4,
	show_statistic = 1 << 5,
};

void	lem_options();

#endif
