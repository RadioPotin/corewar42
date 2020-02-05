/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_argset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:46:13 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/18 12:44:45 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				va_select(t_form *form, va_list arg)
{
	if (form->arg_fg.type == 'p')
	{
		form->va_holder.vptr = va_arg(arg, void *);
		return (0);
	}
	else if (ft_strchr("dDi", form->arg_fg.type))
		return (diva(&form, arg));
	else if (ft_strchr("sS", form->arg_fg.type))
		return (sva(&form, arg));
	else if (ft_strchr("cC", form->arg_fg.type))
		return (cva(&form, arg));
	else if (ft_strchr("UuoOxX", form->arg_fg.type))
		return (uva(&form, arg));
	else if (ft_strchr("eEfFgG", form->arg_fg.type))
		return (fva(&form, arg));
	return (-1);
}
