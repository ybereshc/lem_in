/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:05:24 by ybereshc          #+#    #+#             */
/*   Updated: 2018/11/24 19:05:31 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoi(char *str)
{
	intmax_t	res;
	int8_t		sz;

	if (!str)
		return (0);
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sz = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str++ - '0');
	return (res * sz);
}

uintmax_t	ft_str_to_uint(char *str, uint8_t base)
{
	uintmax_t	res;
	size_t		len;
	char		c;

	if (!str || (base > 36 && base < 2))
		return (0);
	len = ft_strlen(str);
	res = 0;
	while (*str)
	{
		c = *str + ((*str >= 'A' && *str <= 'Z') ? 32 : 0);
		if (c < '0' || (c > '9' && c < 'a') || c > 'z')
			return (0);
		c -= 48;
		if (c > 9)
			c -= 39;
		if (c >= base || c >= 36)
			return (0);
		res += c * ft_upow(base, --len);
		str++;
	}
	return (res);
}

intmax_t	ft_str_to_int(char *str)
{
	int8_t	sz;

	if (!str)
		return (0);
	sz = 1;
	if (*str == '-')
		sz = -1;
	if (*str == '-' || *str == '+')
		str++;
	return ((intmax_t)ft_str_to_uint(str, 10) * sz);
}
