/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources_fct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 10:17:29 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/16 18:32:07 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_size(unsigned char c, int use)
{
	if (c == 1)
		return (1);
	if (c == 3)
		return (2);
	if (c == 2)
		return (use == 1 ? 2 : 4);
	return (0);
}

int		get_arg(t_cw *cw, t_proc *prc, unsigned char *str)
{
	unsigned char	arg;
	unsigned char	mask;
	int				i;

	i = 0;
	mask = 0b11000000;
	arg = cw->arena[(prc->pc + 1) % 4096];
	while (i < 4)
	{
		str[i] = (mask >> (2 * i) & arg) >> (2 * (3 - i));
		i++;
	}
	return (0);
}

int		get_hexa(unsigned char *str, int pc, int lenght)
{
	int				ret;
	int				tmp;
	unsigned char	nb[4];

	tmp = 1;
	ft_bzero(nb, 4);
	while (tmp <= lenght)
	{
		nb[4 - tmp] = str[(pc + lenght - tmp) % 4096];
		tmp++;
	}
	ret = nb[3] + 256 * nb[2] + 65536 * nb[1] + 16777216 * nb[0];
	if (lenght == 2)
		ret = (short int)ret;
	return (ret);
}

void	set_key(t_cw *cw, t_proc *prc)
{
	prc->key = cw->arena[prc->pc];
	prc->ready = 1;
	if (prc->key >= 1 && prc->key <= 16)
		prc->waiting = cw->times[prc->key - 1] - 1;
	else
	{
		prc->ready = 0;
		prc->key = 0;
	}
}

int		increment_pc(t_proc *prc, unsigned char *types, int use, int err)
{
	int ret;

	ret = 0;
	ret = types[0] == 1 ? ret + 1 : ret;
	ret = types[0] == 2 && use == 0 ? ret + 4 : ret;
	ret = types[0] == 3 || (types[0] == 2 && use == 1) ? ret + 2 : ret;
	ret = types[1] == 1 ? ret + 1 : ret;
	ret = types[1] == 2 && use == 0 ? ret + 4 : ret;
	ret = types[1] == 3 || (types[1] == 2 && use == 1) ? ret + 2 : ret;
	ret = types[2] == 1 ? ret + 1 : ret;
	ret = types[2] == 2 && use == 0 ? ret + 4 : ret;
	ret = types[2] == 3 || (types[2] == 2 && use == 1) ? ret + 2 : ret;
	prc->pc = (prc->pc + ret + 2) % 4096;
	return (err);
}
