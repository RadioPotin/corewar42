/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:18:19 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 10:19:34 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		count_total(t_token *p)
{
	t_token *save;
	int		total_size;

	total_size = 0;
	save = p;
	while (save)
	{
		p = save;
		while (p)
		{
			total_size += p->size;
			if (p->nature == OP_CMD)
				total_size += add_count(p);
			if (p->nature == DIR_CALL || p->nature == REGISTER)
				p = p->next_token;
			if (p)
				p = p->next_token;
		}
		save = save->next_head;
	}
	return (total_size);
}

void			count(t_token *p, t_parser *point)
{
	t_token *save;
	t_token *start;

	start = p;
	save = p;
	while (save)
	{
		p = save;
		while (p)
		{
			if (p->nature == LABEL_MENTION)
				get_relative(p, save, point);
			p = p->next_token;
		}
		save = save->next_head;
	}
	point->code_size = count_total(start);
}
