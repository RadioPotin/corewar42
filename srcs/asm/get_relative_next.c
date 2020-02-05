/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:33:39 by casautou          #+#    #+#             */
/*   Updated: 2020/01/15 13:49:17 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		add_count(t_token *p)
{
	if (p->nature == OP_CMD)
	{
		if (p->op_code == LIVE || p->op_code == ZJMP
				|| p->op_code == FORK || p->op_code == LFORK)
			return (1);
		else
			return (2);
	}
	return (0);
}

int		count_positive_next(t_token *label_d, int count)
{
	while (label_d)
	{
		if (label_d->nature == OP_CMD)
			count += add_count(label_d);
		else if (label_d->nature == DIR_CALL)
		{
			count += label_d->size;
			label_d = label_d->next_token;
		}
		else if (label_d->nature == REGISTER)
		{
			count += 1;
			label_d = label_d->next_token;
		}
		else
			count += label_d->size;
		label_d = label_d->next_token;
	}
	return (count);
}

int		count_negative_next(t_token *p, int count)
{
	while (p)
	{
		if (p->nature == OP_CMD)
			count += add_count(p);
		else if (p->nature == DIR_CALL)
		{
			count += p->size;
			p = p->next_token;
		}
		else if (p->nature == REGISTER)
		{
			count += 1;
			p = p->next_token;
		}
		else
			count += p->size;
		p = p->next_token;
	}
	return (count);
}
