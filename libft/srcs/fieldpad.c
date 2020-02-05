/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldpad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 11:41:19 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/19 11:50:30 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*spacer(char *fin, t_form *fm, unsigned int i, int len)
{
	i = (fm->arg_fg.fg_justi == '-') ? ft_strlen(fin) : i;
	fin = clean_pad(fin, ' ', i, len);
	return (fin);
}

static char		*zfiller(char *fin, t_form *fm, unsigned int i, int len)
{
	i = (*fin == '-' || *fin == '+' || *fin == ' '
			|| (fm->arg_fg.type == 'o' && fm->arg_fg.fg_prefi == '#')) ? 1 : 0;
	i = (ft_strchr("Xx", fm->arg_fg.type) && fm->arg_fg.fg_prefi == '#') ?
		2 : i;
	fin = clean_pad(fin, '0', i, len);
	return (fin);
}

static char		*fieldpad(char *fin, t_form *fm)
{
	int				len;

	len = fm->arg_fg.fg_width - ft_strlen(fin);
	if (len > 0)
	{
		if (ft_strchr("duiofUD", fm->arg_fg.type)
				|| (ft_strchr("xX", fm->arg_fg.type)
					&& fm->arg_fg.fg_prefi != '#'))
		{
			if (fm->arg_fg.fg_zfill == 1)
				fin = zfiller(fin, fm, 0, len);
			else
				fin = spacer(fin, fm, 0, len);
		}
		else if (ft_strchr("xX", fm->arg_fg.type)
				&& fm->arg_fg.fg_prefi == '#')
		{
			if (fm->arg_fg.fg_zfill == 1)
				fin = clean_pad(fin, '0', 2, len);
			else
				fin = spacer(fin, fm, 0, len);
		}
	}
	return (fin);
}

char			*padrenderer(char *fin, t_form *fm, int len)
{
	len = fm->arg_fg.fg_width - ft_strlen(fin);
	if (len > 0)
		fin = fieldpad(fin, fm);
	return (fin);
}
