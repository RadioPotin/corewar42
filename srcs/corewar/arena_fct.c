/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_fct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:01:46 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 19:22:20 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		absolute_arena(int value)
{
	value %= 4096;
	if (value < 0)
		return (4096 + value);
	return (value);
}

int		print_in_arena(t_cw *cw, t_proc *prc, int src, int dst)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		cw->arena[absolute_arena(prc->pc + dst + i)] = 0;
		i++;
	}
	while (i > 0)
	{
		if (cw->cl)
			cw->p_color[absolute_arena(prc->pc + dst + i - 1)] = prc->player->i;
		cw->arena[absolute_arena(prc->pc + dst + i - 1)] = src & 0x000000ff;
		src = src >> 8;
		i--;
	}
	return (0);
}
