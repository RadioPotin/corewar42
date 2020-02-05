/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:21:01 by casautou          #+#    #+#             */
/*   Updated: 2020/01/16 15:31:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static	int		start_add_sub_next(t_token *ptr, t_parser *p, t_token *save)
{
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (ptr->nature == NEWLINE)
	{
		if (ptr->next_token)
			return (error_code(save, p));
		return (1);
	}
	if (is_com(ptr) == 0)
		return (error_code(ptr, p));
	else
		return (1);
}

int				start_add_sub(t_token *ptr, t_parser *p)
{
	t_token	*save;

	save = ptr;
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	return (start_add_sub_next(ptr, p, save));
}

int				start_aff(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (ptr->nature == NEWLINE)
	{
		if (ptr->next_token)
			return (error_code(save->next_token, p));
		return (1);
	}
	if (is_com(ptr) == 0)
		return (error_code(ptr, p));
	else
		return (1);
}

static int		next_and_or_xor(t_token *ptr, t_parser *p)
{
	if (ptr->nature == NEWLINE)
	{
		if (ptr->next_token)
			return (error_code(ptr->next_token, p));
		return (1);
	}
	if (is_com(ptr) == 0)
		return (error_code(ptr, p));
	else
		return (1);
}

int				start_and_or_xor(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_dir_call(ptr, p)))
		if (!(ptr = is_ind_call(save, p)))
			if (!(ptr = is_reg(save)))
				return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_dir_call(ptr, p)))
		if (!(ptr = is_ind_call(save, p)))
			if (!(ptr = is_reg(save)))
				return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	return (next_and_or_xor(ptr, p));
}
