/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:15 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:15 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_uintlen(uintmax_t num, uint8_t base)
{
	size_t	len;

	if (!base)
		return (0);
	len = 1;
	while (num /= base)
		len++;
	return (len);
}

size_t	ft_intlen(intmax_t num)
{
	return (ft_uintlen((num < 0 ? -num : num), 10) + (num < 0));
}
