/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:50:03 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/23 19:50:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process.h"
#include "libft.h"

void	ft_init(int argc, char **argv, intmax_t options)
{
	if ((g_process.name = ft_strrchr(*argv, '/') + 1) == (char*)1)
		g_process.name = *argv;
	g_process.argc = argc - 1;
	g_process.argv = argv + 1;
	g_process.options = options;
}
