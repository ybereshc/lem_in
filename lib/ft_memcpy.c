/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:15 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:15 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpy2(void *dst, void *src, size_t n)
{
	uint8_t	*dst_tmp;
	uint8_t	*src_tmp;

	dst_tmp = (uint8_t*)dst;
	src_tmp = (uint8_t*)src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}

void		*ft_memcpy(void *dst, void *src, size_t n)
{
	BIG_PIECE	*dst_tmp;
	BIG_PIECE	*src_dst;
	size_t		i;

	if (!n || !src || !dst)
		return (!n ? dst : 0);
	i = n % sizeof(BIG_PIECE);
	n /= sizeof(BIG_PIECE);
	dst_tmp = (BIG_PIECE*)dst;
	src_dst = (BIG_PIECE*)src;
	while (n--)
		*dst_tmp++ = *src_dst++;
	if (i)
		ft_memcpy2(dst_tmp, src_dst, i);
	return (dst);
}
