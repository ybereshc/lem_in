/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 12:42:47 by ybereshc          #+#    #+#             */
/*   Updated: 2019/02/19 12:42:49 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

void	*ft_any_array(size_t count, size_t n)
{
	t_array	*res;

	if (!count || !(res = ft_memalloc(n)))
		return (0);
	if (!(res->ptr = ft_mlc(SIZE(void*, count))))
	{
		free(res);
		return (0);
	}
	res->max = count;
	return (res);
}

void	*ft_array(size_t count)
{
	return (ft_any_array(count, sizeof(t_array)));
}

void	*ft_array_push(void *ary, void *ptr)
{
	t_array	*ary_tmp;
	void	**tmp;

	ary_tmp = ary;
	if (!ary_tmp)
		return (0);
	if (ary_tmp->len >= ary_tmp->max)
	{
		ary_tmp->max *= 3;
		if (!(tmp = ft_mlc(SIZE(void*, ary_tmp->max))))
			return (0);
		ft_memcpy(tmp, ary_tmp->ptr, SIZE(void*, ary_tmp->len));
		free(ary_tmp->ptr);
		ary_tmp->ptr = tmp;
	}
	return (ary_tmp->ptr[ary_tmp->len++] = ptr);
}

void	*ft_array_free(void *ary)
{
	t_array	*ary_tmp;

	ary_tmp = ary;
	if (ary_tmp && ary_tmp->ptr)
		free(ary_tmp->ptr);
	free(ary_tmp);
	return (0);
}
