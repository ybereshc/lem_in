/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:06:16 by ybereshc          #+#    #+#             */
/*   Updated: 2018/11/24 19:06:21 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	char	*res;
	char	*res_tmp;

	if (!str1 || !str2)
		return (ft_strdup(str1 ? str1 : str2));
	if (!(res = ft_mlc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (0);
	res_tmp = res;
	while (*str1)
		*res++ = *str1++;
	while (*str2)
		*res++ = *str2++;
	*res = '\0';
	return (res_tmp);
}

char	*ft_strfjoin(char *str1, char *str2, uint8_t f)
{
	char	*res;

	res = ft_strjoin(str1, str2);
	if (f & 1)
		free(str1);
	if (f & 2)
		free(str2);
	return (res);
}
