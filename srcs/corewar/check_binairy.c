/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binairy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:02:41 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/14 18:30:27 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_binairy(t_cw *cw, char *str)
{
	unsigned char		nb[4];
	unsigned int		magic;

	ft_memcpy(nb, str, 4);
	magic = nb[3] + 256 * nb[2] + 65536 * nb[1] + 16777216 * nb[0];
	if (magic != COREWAR_EXEC_MAGIC)
	{
		cw->error = 3;
		return (-1);
	}
	return (0);
}
