/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 20:07:40 by ybereshc          #+#    #+#             */
/*   Updated: 2018/08/13 20:07:41 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!s1 || !s2 || !n)
		return (0);
	while (--n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)(*s1) - (unsigned char)(*s2));
}

int8_t	ft_strcmp(char *s1, char *s2)
{
	return (ft_strncmp(s1, s2, -1));
}

int8_t	ft_strnequ(char *str1, char *str2, size_t n)
{
	return (!ft_strncmp(str1, str2, n));
}

int8_t	ft_strequ(char *str1, char *str2)
{
	return (!ft_strcmp(str1, str2));
}
