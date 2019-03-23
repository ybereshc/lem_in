/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:33 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:34 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memset2(void *ptr, uint8_t byte, size_t n)
{
	uint8_t	*tmp;

	tmp = (uint8_t*)ptr;
	while (n--)
		*tmp++ = byte;
	return (ptr);
}

void		*ft_memset(void *ptr, uint8_t byte, size_t n)
{
	BIG_PIECE	*big;
	BIG_PIECE	bytes;
	size_t		i;

	if (!ptr)
		return (0);
	i = n % sizeof(BIG_PIECE);
	n /= sizeof(BIG_PIECE);
	ft_memset2(&bytes, byte, sizeof(BIG_PIECE));
	big = (BIG_PIECE*)ptr;
	while (n--)
		*big++ = bytes;
	if (i)
		ft_memset2(big, byte, i);
	return (ptr);
}
