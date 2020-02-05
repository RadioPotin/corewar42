/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 13:58:49 by casautou          #+#    #+#             */
/*   Updated: 2020/01/15 10:57:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int	get_third_number(t_token *p, int i)
{
	i *= 100;
	if (p->nature == REGISTER)
		i += 1;
	else if (p->nature == DIR_CALL)
		i += 10;
	else
		i += 11;
	return (i * 100);
}

static	int	get_second_number(t_token *p, int i)
{
	i *= 100;
	if (p->nature == REGISTER)
	{
		i += 1;
		p = p->next_token;
	}
	else if (p->nature == DIR_CALL)
	{
		i += 10;
		p = p->next_token;
	}
	else
		i += 11;
	p = p->next_token;
	if (p->nature == SEPARATOR)
		return (get_third_number(p->next_token, i));
	return (i * 10000);
}

static	int	get_first_number(t_token *p, int i)
{
	if (p->nature == REGISTER)
	{
		i = 1;
		p = p->next_token;
	}
	else if (p->nature == DIR_CALL)
	{
		i = 10;
		p = p->next_token;
	}
	else
		i = 11;
	p = p->next_token->next_token;
	return (get_second_number(p, i));
}

int			get_args(t_token *p)
{
	int i;

	i = 0;
	if (p->nature != OP_CMD)
		return (-1);
	else if (p->op_code == AFF)
		return (1000000);
	return (get_first_number(p->next_token, i));
}
