/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:19:00 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 12:09:31 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			error_code(t_token *ptr, t_parser *p)
{
	if (p->err2 == 1)
		return (0);
	p->err2 = 1;
	if (!(p->verbose))
	{
		ft_printf("ERROR.\n");
		return (0);
	}
	if (p->verbose == 1)
	{
		ft_printf("ERROR: Wrong token in code.\n");
		return (0);
	}
	if (p->verbose == 2)
	{
		if (!(ptr))
			return (0);
		ft_printf("ERROR: Wrong token in code, located line %d, column %d.\n"
		, ptr->location.line, ptr->location.offset);
		return (0);
	}
	return (0);
}

int			error_header(t_token *ptr, t_parser *p)
{
	if (p->err2 == 1)
		return (0);
	p->err2 = 1;
	if (!(p->verbose))
	{
		ft_printf("ERROR.\n");
		return (0);
	}
	if (p->verbose == 1)
	{
		ft_printf("ERROR: Wrong token in header.\n");
		return (0);
	}
	if (p->verbose == 2)
	{
		if (!(ptr))
			return (0);
		ft_printf("ERROR: Wrong token in header, located line %d, column %d.\n"
		, ptr->location.line, ptr->location.offset);
		return (0);
	}
	return (0);
}

t_token		*error_code_null(t_token *ptr, t_parser *p)
{
	if (p->err2 == 1)
		return (0);
	p->err2 = 1;
	if (!(p->verbose))
	{
		ft_printf("ERROR.\n");
		return (NULL);
	}
	if (p->verbose == 1)
	{
		ft_printf("ERROR: Wrong token in code.\n");
		return (NULL);
	}
	if (p->verbose == 2)
	{
		if (!(ptr))
			return (0);
		ft_printf("ERROR: Wrong token in code, located line %d, column %d.\n"
		, ptr->location.line, ptr->location.offset);
		return (NULL);
	}
	return (NULL);
}
