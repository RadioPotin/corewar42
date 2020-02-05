/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_aff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:02:03 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/17 10:10:00 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		aff_fct(t_cw *cw, t_proc *prc)
{
	unsigned char	types[4];
	unsigned char	aff;
	int				use;
	int				size;

	if (get_arg(cw, prc, types) == -1)
		return (increment_pc(prc, types, 0, -1));
	if ((types[0] != 1) || !(size = get_size(types[0], 0)))
		return (increment_pc(prc, types, 0, -1));
	use = get_hexa(cw->arena, prc->pc + 2, size);
	if (use > 16 || use < 1)
		return (increment_pc(prc, types, 0, -1));
	aff = prc->regs[use - 1] & 0xff;
	ft_printf("%c", aff);
	return (increment_pc(prc, types, 0, 0));
}
