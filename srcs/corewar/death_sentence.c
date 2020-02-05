/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_sentence.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelleti <jpelleti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 09:37:46 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/14 09:39:59 by jpelleti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	misc_death(t_cw *cw, t_proc *prc)
{
	if (prc->next && prc->prev)
	{
		prc->next->prev = prc->prev;
		prc->prev->next = prc->next;
	}
	else if (prc->next)
	{
		prc->next->prev = NULL;
		cw->procs = prc->next;
	}
	else if (prc->prev)
		prc->prev->next = NULL;
	else
		cw->procs = NULL;
	free(prc);
	prc = NULL;
}

void		death_sentence(t_cw *cw, t_proc *prc)
{
	t_proc	*tmp;

	while (prc)
	{
		tmp = prc->next;
		if (prc->live == 0)
			misc_death(cw, prc);
		else
			prc->live = 0;
		prc = tmp;
	}
}
