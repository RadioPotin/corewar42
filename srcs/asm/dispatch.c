/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:18:34 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 12:45:41 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				next_dispatch(t_token *ptr, t_parser *p, int i)
{
	if (i == 1)
		return (start_add_sub(ptr->next_token, p));
	if (i == 2)
		return (start_aff(ptr->next_token, p));
	if (i == 3)
		return (start_and_or_xor(ptr->next_token, p));
	if (i == 4)
		return (start_ld_lld(ptr->next_token, p));
	if (i == 5)
		return (start_ldi_lldi(ptr->next_token, p));
	if (i == 6)
		return (start_live_zjmp_fork_lfork(ptr->next_token, p));
	if (i == 7)
		return (start_st(ptr->next_token, p));
	if (i == 8)
		return (start_sti(ptr->next_token, p));
	return (0);
}

int				check_op_cmd(t_token *ptr, t_parser *p)
{
	int i;

	if (!ptr)
		return (0);
	if (!(ptr->nature == OP_CMD))
		return (0);
	i = get_index(ptr);
	return (next_dispatch(ptr, p, i));
}

static t_token	*label_d(t_token *ptr, t_parser *p)
{
	if (ptr->next_token && ptr->next_token->nature == NEWLINE)
	{
		ptr = skip_coms(ptr->next_head);
		if (check_op_cmd(ptr, p) == 1)
			return (ptr->next_head);
		return (error_code_null(ptr, p));
	}
	if (is_com(ptr->next_token))
	{
		ptr = skip_coms(ptr->next_head);
		if (check_op_cmd(ptr, p) == 1)
			return (ptr->next_head->next_head);
		return (error_code_null(ptr, p));
	}
	if (check_op_cmd(ptr->next_token, p) == 1)
		return (ptr->next_head);
	return (error_code_null(ptr, p));
}

t_token			*dispatch(t_token *ptr, t_parser *p)
{
	if (ptr->nature == LABEL_DECLARATION)
		return (label_d(ptr, p));
	else if (ptr->nature == OP_CMD)
	{
		if (check_op_cmd(ptr, p) == 1)
			return (ptr->next_head);
	}
	else
	{
		error_code(ptr, p);
		return (NULL);
	}
	return (NULL);
}
