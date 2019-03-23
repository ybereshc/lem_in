/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybereshc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:04:27 by ybereshc          #+#    #+#             */
/*   Updated: 2018/11/24 19:04:38 by ybereshc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "libft.h"

t_list	*ft_list(void)
{
	return (ft_memalloc(sizeof(t_list)));
}

t_el	*ft_list_push(t_list *list, void *ptr)
{
	t_el	*el;

	if (!list || !(el = ft_mlc(sizeof(t_el))))
		return (0);
	el->ptr = ptr;
	el->next = 0;
	if (list->last)
		list->last->next = el;
	list->last = el;
	if (!list->head)
		list->head = el;
	list->count++;
	return (el);
}

t_el	*ft_list_remove(t_list *list, void *ptr)
{
	t_el	**el;
	t_el	*tmp;
	t_el	*perent;

	if (!list)
		return (0);
	el = &list->head;
	perent = 0;
	while (*el)
	{
		if ((*el)->ptr == ptr)
		{
			if ((tmp = *el) == list->last)
				list->last = perent;
			*el = (*el)->next;
			free(tmp);
			list->count--;
			return (ptr);
		}
		perent = *el;
		el = &(*el)->next;
	}
	return (0);
}

void	ft_list_free(t_list *list)
{
	t_el	*el;
	t_el	*tmp;

	if (!list)
		return ;
	tmp = list->head;
	while ((el = tmp))
	{
		tmp = el->next;
		free(el);
	}
	free(list);
}

void	**ft_list_to_array(t_list *list)
{
	void	**ary;
	int		i;
	t_el	*el;

	if (!list || !(ary = ft_mlc(sizeof(void*) * list->count)))
		return (0);
	i = 0;
	el = list->head;
	while (el)
	{
		ary[i++] = el->ptr;
		el = el->next;
	}
	return (ary);
}
