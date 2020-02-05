/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <evogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:15:52 by evogel            #+#    #+#             */
/*   Updated: 2019/08/06 13:01:34 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lists	*ft_lstmap(t_lists *lst, t_lists *(*f)(t_lists *elem))
{
	t_lists	*begin;
	t_lists	*new;
	t_lists	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	begin = new;
	lst = lst->next;
	while (lst && new)
	{
		tmp = f(lst);
		new->next = tmp;
		new = tmp;
		lst = lst->next;
	}
	if (new == NULL)
		ft_lstdel(&begin, ft_bzero);
	return (begin);
}
