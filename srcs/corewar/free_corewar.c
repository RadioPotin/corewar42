/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:50:02 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/16 15:23:36 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_corewar(t_cw *cw)
{
	t_proc	*prc;
	t_proc	*tmp;

	prc = cw->procs;
	while (prc)
	{
		tmp = prc->next;
		prc->next = NULL;
		prc->prev = NULL;
		prc->player = NULL;
		free(prc);
		prc = tmp;
	}
	prc = NULL;
	cw->procs = NULL;
}
