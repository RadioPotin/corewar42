/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaf_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:46:40 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 14:34:32 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*f_precirender(long double lng, t_form *fm, int preci)
{
	char	*fin;

	if (preci == -1 || preci == 6)
		fin = ft_ldbltoa(lng, 6, fm->negative);
	else
		fin = ft_ldbltoa(lng, preci, fm->negative);
	fin = (fm->arg_fg.fg_prefi == '#' && fm->arg_fg.fg_preci <= 0)
		? clean_pad(fin, '.', ft_strlen(fin), 1) : fin;
	return (fin);
}

char	*f_renderer(t_form **fm)
{
	char	*fin;
	int		len;

	fin = f_precirender((*fm)->va_holder.ldble, *fm, (*fm)->arg_fg.fg_preci);
	len = ((*fm)->negative == 1) ? ft_strlen(fin) - 1 : ft_strlen(fin);
	if ((*fm)->negative < 1 && (*fm)->arg_fg.fg_signs)
		fin = clean_pad(fin, *ft_strchr("+ ", (*fm)->arg_fg.fg_signs), 0, 1);
	if ((*fm)->arg_fg.fg_zfill == 1 || (*fm)->arg_fg.fg_width > 0)
		fin = padrenderer(fin, *fm, len);
	return (fin);
}
