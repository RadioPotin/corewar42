/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:20:41 by evogel            #+#    #+#             */
/*   Updated: 2018/11/20 15:27:14 by evogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst(t_list *lst, void (*put)(void*))
{
	while (lst)
	{
		put(lst->content);
		ft_putstr(" -> ");
		lst = lst->next;
	}
	ft_putstr(" NULL\n");
}
