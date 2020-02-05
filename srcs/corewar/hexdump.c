/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:09:09 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/16 18:31:07 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	display(t_cw *cw, int i, int col)
{
	if (i != 0 && i % 64 == 0)
		ft_printf("\n");
	if (i != 4096 && i % 64 == 0)
		ft_printf("0x0%.3x : ", i);
	if (col == 1)
		ft_printf("\033[31m%.2x\033[0m ", cw->arena[i]);
	else if (col == 10)
		ft_printf("\033[30;41m%.2x\033[0m ", cw->arena[i]);
	else if (col == 2)
		ft_printf("\033[32m%.2x\033[0m ", cw->arena[i]);
	else if (col == 20)
		ft_printf("\033[30;42m%.2x\033[0m ", cw->arena[i]);
	else if (col == 3)
		ft_printf("\033[34m%.2x\033[0m ", cw->arena[i]);
	else if (col == 30)
		ft_printf("\033[30;44m%.2x\033[0m ", cw->arena[i]);
	else if (col == 4)
		ft_printf("\033[35m%.2x\033[0m ", cw->arena[i]);
	else if (col == 40)
		ft_printf("\033[30;45m%.2x\033[0m ", cw->arena[i]);
	else if (col == 50)
		ft_printf("\033[30;47m%.2x\033[0m ", cw->arena[i]);
	else
		ft_printf("%.2x ", cw->arena[i]);
}

static int	find_color(t_cw *cw, t_proc *prc, int i)
{
	while (prc)
	{
		if (i == prc->pc)
			return (cw->p_color[i] * 10);
		prc = prc->next;
	}
	return (cw->p_color[i]);
}

int			ft_hexdump(t_cw *cw)
{
	int i;
	int col;

	col = 0;
	i = 0;
	while (i < 4096)
	{
		if (cw->cl)
			col = find_color(cw, cw->procs, i);
		display(cw, i, col);
		i++;
		col = 0;
	}
	ft_printf("\n");
	return (0);
}
