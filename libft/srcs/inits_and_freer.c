/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_freer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:11:12 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/20 14:29:01 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		init_form_pkg(t_form *form_pkg)
{
	form_pkg->negative = 0;
	form_pkg->fg_va_holder = -1;
	form_pkg->native_index = -1;
	form_pkg->native_form = NULL;
	form_pkg->final_form = NULL;
	form_pkg->finfg = -1;
	form_pkg->arg_fg.fg_prefi = '\0';
	form_pkg->arg_fg.fg_apost = '\0';
	form_pkg->arg_fg.fg_signs = '\0';
	form_pkg->arg_fg.fg_justi = '\0';
	form_pkg->arg_fg.fg_zfill = -1;
	form_pkg->arg_fg.fg_width = -1;
	form_pkg->arg_fg.fg_preci = -1;
	form_pkg->arg_fg.fg_fsize = NULL;
	form_pkg->arg_fg.type = '\0';
	return (0);
}

void	init_gvars(void)
{
	unsigned int i;

	i = 0;
	g_buffi = 0;
	while (i < BUFFSIZE)
		g_buff[i++] = '\0';
}

int		init_fg(t_flags *fg)
{
	fg->fg_prefi = '0';
	fg->fg_apost = '0';
	fg->fg_signs = '0';
	fg->fg_justi = '0';
	fg->fg_zfill = -1;
	fg->fg_width = -1;
	fg->fg_preci = -1;
	fg->fg_fsize = NULL;
	fg->type = '0';
	return (0);
}

void	t_form_freer(t_form *form)
{
	if (form->native_form != NULL)
		ft_strdel(&(form)->native_form);
	if (form->final_form != NULL)
		ft_strdel(&(form)->final_form);
	if (form->arg_fg.fg_fsize != NULL)
		ft_strdel(&(form)->arg_fg.fg_fsize);
}
