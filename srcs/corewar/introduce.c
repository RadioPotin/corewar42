/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:19:42 by jpelleti          #+#    #+#             */
/*   Updated: 2020/01/13 20:03:03 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		introduce(t_cw *cw)
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < cw->players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
		cw->player[i].number, cw->player[i].c_size,
		cw->player[i].name, cw->player[i].comment);
		i++;
	}
	return (0);
}
