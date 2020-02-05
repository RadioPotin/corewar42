/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 10:35:49 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/09 15:18:47 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		create_process(t_cw *cw, t_play *pl)
{
	t_proc	*new;
	t_proc	*tmp;

	if (!(new = malloc(sizeof(t_proc))))
		return (-1);
	ft_bzero(new, sizeof(t_proc));
	tmp = cw->procs;
	new->regs[0] = pl->number;
	new->player = pl;
	if (!tmp)
	{
		new->next = NULL;
		cw->procs = new;
		return (0);
	}
	new->next = tmp;
	new->prev = NULL;
	cw->procs->prev = new;
	cw->procs = new;
	return (0);
}
