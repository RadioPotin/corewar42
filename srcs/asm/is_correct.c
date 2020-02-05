/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:20:12 by casautou          #+#    #+#             */
/*   Updated: 2019/12/04 18:52:18 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_correct(t_parser *p)
{
	t_token *ptr;
	t_token *save;

	ptr = NULL;
	if (!(ptr = check_header(p)))
		return (0);
	save = skip_coms(ptr);
	while (ptr)
	{
		ptr = skip_coms(ptr);
		if (ptr->nature == END)
			break ;
		if (!(ptr = dispatch(ptr, p)))
			return (0);
	}
	check_t_dir_size(save);
	count(save, p);
	return (1);
}
