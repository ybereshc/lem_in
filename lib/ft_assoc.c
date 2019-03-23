/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:47 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:49 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

t_assoc	*ft_assoc(size_t n)
{
	t_assoc	*res;

	if (!n || !(res = ft_mlc(sizeof(t_assoc))))
		return (0);
	res->key = ft_mlc(SIZE(char*, n));
	res->ptr = ft_mlc(SIZE(void*, n));
	if (!res->key || !res->ptr)
		return (0);
	res->max = n;
	res->len = 0;
	return (res);
}

void	*ft_assoc_push(t_assoc *ary, char *key, void *ptr)
{
	void	**tmp;

	if (!ary)
		return (0);
	if (ary->len >= ary->max)
	{
		ary->max *= 3;
		if (!(tmp = ft_mlc(SIZE(char*, ary->max))))
			return (0);
		ft_memcpy(tmp, ary->key, SIZE(void*, ary->len));
		free(ary->key);
		ary->key = tmp;
		if (!(tmp = ft_mlc(SIZE(void*, ary->max))))
			return (0);
		ft_memcpy(tmp, ary->ptr, SIZE(void*, ary->len));
		free(ary->ptr);
		ary->ptr = tmp;
	}
	ary->key[ary->len] = key;
	ary->ptr[ary->len++] = ptr;
	return (ptr);
}
