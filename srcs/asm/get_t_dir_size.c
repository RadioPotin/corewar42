/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_t_dir_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:20:03 by casautou          #+#    #+#             */
/*   Updated: 2019/12/03 15:13:26 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		apply_size(t_token *ptr, int i)
{
	while (ptr)
	{
		if (ptr->nature == DIR_CALL)
			ptr->size = i;
		ptr = ptr->next_token;
	}
}

static void		get_t_dir_size(t_token *ptr)
{
	if (!(ptr))
		return ;
	if (ptr->op_code == ZJMP || ptr->op_code == LDI || ptr->op_code == STI
	|| ptr->op_code == FORK || ptr->op_code == LLDI || ptr->op_code == LFORK)
		apply_size(ptr, 2);
	else
		apply_size(ptr, 4);
}

void			check_t_dir_size(t_token *ptr)
{
	t_token *save;

	save = ptr;
	while (save)
	{
		while (ptr)
		{
			if (ptr->nature == OP_CMD)
				get_t_dir_size(ptr);
			ptr = ptr->next_token;
		}
		ptr = save->next_head;
		save = ptr;
	}
}
