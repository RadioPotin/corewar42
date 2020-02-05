/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_champs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:17:31 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/13 18:10:24 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	put_in_pcolor(t_cw *cw, int calc, int number, int size)
{
	int		i;

	cw->player[number - 1].i = number;
	i = calc;
	while (i < calc + size && i < 4096)
	{
		cw->p_color[i] = number;
		i++;
	}
}

static void	fill_pcolor(t_cw *cw)
{
	int	i;

	i = 0;
	while (i < 4096)
	{
		cw->p_color[i] = 5;
		i++;
	}
}

int			place_champs(t_cw *cw)
{
	int		i;
	int		calc;
	t_proc	*tmp;

	i = cw->players - 1;
	tmp = cw->procs;
	if (cw->cp)
		fill_pcolor(cw);
	while (i >= 0)
	{
		calc = 4096 / cw->players * i;
		ft_memcpy(&cw->arena[calc], cw->player[i].champ + 2192,
			cw->player[i].c_size);
		if (cw->cl)
			put_in_pcolor(cw, calc, i + 1, cw->player[i].c_size);
		tmp->pc = calc;
		tmp->key = cw->arena[tmp->pc];
		tmp->ready = 1;
		tmp->waiting = cw->times[tmp->key - 1];
		tmp = tmp->next;
		i--;
	}
	return (0);
}
