/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:21:18 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 13:04:13 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			start_ld_lld(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_dir_call(ptr, p)))
		if (!(ptr = is_ind_call(save, p)))
			return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
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

static	int	start_ldi_lldi_next(t_token *ptr, t_parser *p, t_token *save)
{
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
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

int			start_ldi_lldi(t_token *ptr, t_parser *p)
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
		if (!(ptr = is_reg(save)))
			return (error_code(save, p));
	save = ptr;
	return (start_ldi_lldi_next(ptr, p, save));
}

int			start_live_zjmp_fork_lfork(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_dir_call(ptr, p)))
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

int			start_st(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_reg(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_reg(ptr)))
		if (!(ptr = is_ind_call(save, p)))
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
