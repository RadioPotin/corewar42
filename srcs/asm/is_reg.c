/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:20:49 by casautou          #+#    #+#             */
/*   Updated: 2020/01/15 12:30:22 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token	*is_reg(t_token *ptr)
{
	if (!(ptr))
		return (NULL);
	if (!(ptr->nature == REGISTER))
		return (NULL);
	ptr = ptr->next_token;
	if (!(ptr))
		return (NULL);
	if (!(ptr->nature == LITERAL_NB))
		return (NULL);
	return (ptr->next_token);
}

t_token	*is_sep(t_token *ptr)
{
	if (!ptr)
		return (NULL);
	if (!(ptr->nature == SEPARATOR))
		return (NULL);
	return (ptr->next_token);
}
