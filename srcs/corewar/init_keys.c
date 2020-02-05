/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:03:42 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 17:09:15 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_p_key(t_pfct *pft)
{
	ft_bzero(pft, 16);
	pft[0] = &live_fct;
	pft[1] = &ld_fct;
	pft[2] = &st_fct;
	pft[3] = &add_fct;
	pft[4] = &sub_fct;
	pft[5] = &and_fct;
	pft[6] = &or_fct;
	pft[7] = &xor_fct;
	pft[8] = &zjmp_fct;
	pft[9] = &ldi_fct;
	pft[10] = &sti_fct;
	pft[11] = &fork_fct;
	pft[12] = &lld_fct;
	pft[13] = &lldi_fct;
	pft[14] = &lfork_fct;
	pft[15] = &aff_fct;
}

void	init_times_key(int *times)
{
	ft_bzero(times, 16);
	times[0] = 10;
	times[1] = 5;
	times[2] = 5;
	times[3] = 10;
	times[4] = 10;
	times[5] = 6;
	times[6] = 6;
	times[7] = 6;
	times[8] = 20;
	times[9] = 25;
	times[10] = 25;
	times[11] = 800;
	times[12] = 10;
	times[13] = 50;
	times[14] = 1000;
	times[15] = 2;
}
