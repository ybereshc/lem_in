/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:48:52 by ybereshc          #+#    #+#             */
/*   Updated: 2018/10/22 13:48:54 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *str1, char *str2, size_t n)
{
	char	*res;

	res = str1;
	if (!n)
		return (str1);
	while (*str1)
		str1++;
	if (!(str2 = ft_memcpy(str1, str2, n)))
		return (0);
	str2[n] = '\0';
	return (res);
}

char	*ft_strcat(char *str1, char *str2)
{
	return (ft_strncat(str1, str2, ft_strlen(str2)));
}

char	*ft_strfcat(char *str1, char *str2)
{
	str1 = ft_strcat(str1, str2);
	free(str2);
	return (str1);
}
