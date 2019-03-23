/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 19:50:03 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/23 19:50:05 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mlc(size_t n)
{
	void	*ptr;

	if ((ptr = malloc(n)))
		return (ptr);
	if (g_process.options & MLC_ERROR)
		ft_dprintf(2, "Malloc: failed to allocate %U bytes.\n", n);
	if (g_process.options & MLC_EXIT)
		exit(0);
	return (0);
}

void	*ft_memalloc(size_t n)
{
	return (ft_bzero(ft_mlc(n), n));
}

void	*ft_free(int n, ...)
{
	va_list	ap;

	if (n < 1)
		return (0);
	va_start(ap, n);
	while (n--)
		free(va_arg(ap, void*));
	va_end(ap);
	return (0);
}
