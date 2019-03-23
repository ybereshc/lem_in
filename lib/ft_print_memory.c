/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:01:48 by exam              #+#    #+#             */
/*   Updated: 2018/11/27 11:22:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_memory_char(uint8_t *byte, size_t n)
{
	size_t	i;
	char	c;

	i = 0;
	while (i < n && i < 16)
	{
		c = ((*byte >= 33 && *byte <= 126) ? (char)*byte : '.');
		write(1, &c, 1);
		i++;
		byte++;
	}
	write(1, "\n", 1);
}

static void	ft_print_memory_hex(uint8_t *byte, size_t n)
{
	char	c;
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i < n)
		{
			c = *byte / 16;
			c += (c > 9 ? 87 : 48);
			write(1, &c, 1);
			c = *byte % 16;
			c += (c > 9 ? 87 : 48);
			write(1, &c, 1);
		}
		else
			write(1, "  ", 2);
		byte++;
		i++;
		if (!(i % 2))
			write(1, " ", 1);
	}
}

void		ft_print_memory(void *ptr, size_t size)
{
	uint8_t	*byte;
	size_t	i;

	i = 0;
	byte = (uint8_t*)ptr;
	while (i < size)
	{
		ft_print_memory_hex(byte, size - i);
		ft_print_memory_char(byte, size - i);
		i += 16;
		byte += 16;
	}
}

void		ft_print_strary(char **strary)
{
	if (!strary)
		return ;
	while (*strary)
		ft_printf("%s\n", *strary++);
}
