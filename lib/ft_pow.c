/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 19:32:44 by ybereshc          #+#    #+#             */
/*   Updated: 2018/08/10 19:33:42 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_upow(uintmax_t nb, uintmax_t pow)
{
	uintmax_t res;

	if (pow < 1)
		return (pow ? 0 : 1);
	res = 1;
	while (pow--)
		res *= nb;
	return (res);
}

intmax_t	ft_pow(intmax_t nb, uintmax_t pow)
{
	intmax_t res;

	if (pow < 1)
		return (pow ? 0 : 1);
	res = 1;
	while (pow--)
		res *= nb;
	return (res);
}
