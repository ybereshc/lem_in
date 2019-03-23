/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:46:51 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:46:52 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_abs(intmax_t n)
{
	return (n < 0 ? -n : n);
}

uint8_t		ft_odd(intmax_t n)
{
	return (n % 2);
}

uint8_t		ft_even(intmax_t n)
{
	return (!ft_odd(n));
}

uint8_t		ft_negative(intmax_t n)
{
	return (n < 0);
}

uint8_t		ft_positive(intmax_t n)
{
	return (!ft_negative(n));
}
