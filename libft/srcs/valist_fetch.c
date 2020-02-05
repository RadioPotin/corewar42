/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valist_fetch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:30:48 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/26 16:55:19 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cva(t_form **form, va_list arg)
{
	if ((*form)->arg_fg.type == 'c' || (*form)->arg_fg.type == 'C')
	{
		(*form)->va_holder.car = va_arg(arg, int);
		return (1);
	}
	return (-1);
}

int		sva(t_form **form, va_list arg)
{
	if ((*form)->arg_fg.type == 's' || (*form)->arg_fg.type == 'S')
	{
		(*form)->va_holder.str = va_arg(arg, char *);
		return (3);
	}
	return (-1);
}

int		diva(t_form **form, va_list arg)
{
	if ((*form)->arg_fg.fg_fsize == NULL
			|| ft_strcmp((*form)->arg_fg.fg_fsize, "h") == 0
			|| ft_strcmp((*form)->arg_fg.fg_fsize, "hh") == 0)
		(*form)->va_holder.intmaxt = (intmax_t)va_arg(arg, int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "l") == 0
			|| (*form)->arg_fg.type == 'D')
		(*form)->va_holder.intmaxt = (intmax_t)va_arg(arg, long int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "ll") == 0)
		(*form)->va_holder.intmaxt = (intmax_t)va_arg(arg, long long int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "z") == 0)
		(*form)->va_holder.intmaxt = (intmax_t)va_arg(arg, size_t);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "j") == 0)
		(*form)->va_holder.intmaxt = va_arg(arg, intmax_t);
	if ((*form)->va_holder.intmaxt < 0)
	{
		(*form)->negative = 1;
		(*form)->va_holder.intmaxt = -(*form)->va_holder.intmaxt;
	}
	(*form)->va_holder.uintmaxt = (*form)->va_holder.intmaxt;
	return (5);
}

int		uva(t_form **form, va_list arg)
{
	if ((*form)->arg_fg.fg_fsize == NULL
			|| ft_strcmp((*form)->arg_fg.fg_fsize, "h") == 0
			|| ft_strcmp((*form)->arg_fg.fg_fsize, "hh") == 0)
		(*form)->va_holder.uintmaxt = (uintmax_t)va_arg(arg, unsigned int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "l") == 0
			|| (*form)->arg_fg.type == 'U')
		(*form)->va_holder.uintmaxt = va_arg(arg, unsigned long int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "ll") == 0)
		(*form)->va_holder.uintmaxt = va_arg(arg, unsigned long long int);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "z") == 0)
		(*form)->va_holder.uintmaxt = (uintmax_t)va_arg(arg, size_t);
	else if (ft_strcmp((*form)->arg_fg.fg_fsize, "j") == 0)
		(*form)->va_holder.uintmaxt = va_arg(arg, uintmax_t);
	return (5);
}

int		fva(t_form **form, va_list arg)
{
	if ((*form)->arg_fg.fg_fsize != NULL)
	{
		(*form)->va_holder.ldble = va_arg(arg, long double);
		if ((*form)->va_holder.ldble < 0)
		{
			(*form)->negative = 1;
			(*form)->va_holder.ldble = -(*form)->va_holder.ldble;
		}
		return (6);
	}
	(*form)->va_holder.ldble = (long double)va_arg(arg, double);
	if ((*form)->va_holder.ldble < 0)
	{
		(*form)->negative = 1;
		(*form)->va_holder.ldble = -(*form)->va_holder.ldble;
	}
	return (6);
}
