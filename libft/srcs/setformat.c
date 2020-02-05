/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:38:48 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/21 14:17:01 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		fg_checker(t_form *fg)
{
	if (fg->arg_fg.fg_prefi == '#' && fg->arg_fg.fg_preci == -1
			&& ft_strchr("aAeEfFgG", fg->arg_fg.type))
		fg->arg_fg.fg_preci = 0;
	if ((fg->arg_fg.fg_signs == '+' || fg->arg_fg.fg_signs == ' ')
			&& ft_strchr("oOxXcsp", fg->arg_fg.type))
		fg->arg_fg.fg_signs = '\0';
	if (fg->arg_fg.fg_zfill == 1
			&& (fg->arg_fg.fg_justi == '-' || fg->arg_fg.fg_preci != -1)
			&& ft_strchr("iuxXOodD", fg->arg_fg.type))
		fg->arg_fg.fg_zfill = -1;
	if (fg->arg_fg.fg_zfill == 1 && ft_strchr("csp", fg->arg_fg.type))
		fg->arg_fg.fg_zfill = -1;
	return (1);
}

static int		format_extract(t_form form, va_list arg)
{
	form.fg_va_holder = va_select(&form, arg);
	return (tostrdispatch(&form));
}

int				check_set_form(const char *ptr, va_list arg)
{
	int		len;
	t_form	form;

	init_form_pkg(&form);
	len = ft_strichrset(ptr + 1, CONVTYPE);
	form.native_index = g_buffi;
	form.native_form = ft_strsub(ptr, 0, len + 2);
	parse_set_fg_flags(&form, form.native_form);
	if (fg_checker(&form) == 1)
	{
		len = format_extract(form, arg);
		if (len == -1)
		{
			t_form_freer(&form);
			return (0);
		}
		t_form_freer(&form);
		return (len);
	}
	return (0);
}
