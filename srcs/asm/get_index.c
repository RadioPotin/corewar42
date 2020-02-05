/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:19:20 by casautou          #+#    #+#             */
/*   Updated: 2019/12/03 13:03:12 by casautou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_index(t_token *ptr)
{
	if (ptr->op_code == ADD || ptr->op_code == SUB)
		return (1);
	if (ptr->op_code == AFF)
		return (2);
	if (ptr->op_code == AND || ptr->op_code == OR || ptr->op_code == XOR)
		return (3);
	if (ptr->op_code == LD || ptr->op_code == LLD)
		return (4);
	if (ptr->op_code == LDI || ptr->op_code == LLDI)
		return (5);
	if (ptr->op_code == LIVE || ptr->op_code == ZJMP || ptr->op_code == FORK
	|| ptr->op_code == LFORK)
		return (6);
	if (ptr->op_code == ST)
		return (7);
	if (ptr->op_code == STI)
		return (8);
	return (0);
}
