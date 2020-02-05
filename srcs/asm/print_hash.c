/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:29:05 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/10 16:48:25 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			print_hash(t_parser *box)
{
	int		i;
	t_hash	*hash;

	i = 0;
	if (!box->verbose)
		return ;
	ft_printf("\tHASHTABLE LAYOUT\n");
	while (i < HASHTABLE_SIZE)
	{
		if (box->labels[i].label_name != NULL)
		{
			hash = &box->labels[i];
			ft_printf("Hashtable[%03d]--> label ( %s )\n", i, hash->label_name);
			while (hash->next_col)
			{
				hash = hash->next_col;
				ft_printf("Collision with ( %s )\n", hash->label_name);
			}
		}
		i++;
	}
	ft_printf("\n");
}
