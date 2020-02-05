/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sti.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:21:32 by casautou          #+#    #+#             */
/*   Updated: 2020/01/16 15:34:21 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		start_sti_next(t_token *ptr, t_parser *p, t_token *save)
{
	if (!(ptr = is_sep(ptr)))
		return (error_code(save, p));
	save = ptr;
	if (!(ptr = is_dir_call(ptr, p)))
	{
		if (!(ptr = is_reg(save)))
			return (error_code(save, p));
	}
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

int				start_sti(t_token *ptr, t_parser *p)
{
	t_token *save;

	save = ptr;
	if (!(ptr = is_reg(ptr)))
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
	return (start_sti_next(ptr, p, save));
}
