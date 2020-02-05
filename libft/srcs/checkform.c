/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:15:37 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/21 18:54:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_set_fg_pre(t_form **fg, char *format)
{
	char	*ptr;

	ptr = NULL;
	if ((ptr = ft_strrchr(format, '.')) != NULL)
	{
		(*fg)->arg_fg.fg_preci = 0;
		if (ft_strchr(INTEGERS, (*fg)->arg_fg.type))
			(*fg)->arg_fg.fg_zfill = -1;
	}
	if (ptr && ft_isdigit(ptr[1]))
		(*fg)->arg_fg.fg_preci = ft_atoi(ptr + 1);
	if ((*fg)->arg_fg.type == 'c')
		(*fg)->arg_fg.fg_preci = -1;
	return (0);
}

int		parse_set_fg_siz(t_form **fg, char *format)
{
	char	*ptr;
	char	fsize;

	fsize = *ft_strrchrset(format, SIZE);
	if ((fsize != 'L' && (ft_strrchrset(format, "eEfFgG")) != NULL)
			|| (fsize != 'l' && (ft_strrchrset(format, "cs")) != NULL)
			|| (fsize == 'L'
				&& (ft_strrchrset(format, "cspdDiUuoOxX")) != NULL))
		return (0);
	ptr = ft_strrchrset(format, SIZE);
	if (*ptr == 'l' || *ptr == 'h')
		if (*(ptr - 1) == *ptr)
		{
			(*fg)->arg_fg.fg_fsize = ft_strnew(2);
			ft_memset((char *)(*fg)->arg_fg.fg_fsize, fsize, 2);
			return (1);
		}
	(*fg)->arg_fg.fg_fsize = ft_strnew(1);
	(*fg)->arg_fg.fg_fsize[0] = fsize;
	return (1);
}

int		parse_set_fg_wid(t_form **fg, char *format)
{
	int i;

	i = 0;
	while (format[i] && format[i] != '.'
			&& (!ft_isdigit(format[i]) || format[i] == '0'))
		i++;
	if (format[i] == '.')
		return (0);
	(*fg)->arg_fg.fg_width = ft_atoi(&format[i]);
	return (1);
}

int		parse_set_fg_pad(t_form **form, char *format)
{
	int i;

	if ((i = ft_strichrset(format, "'")) != -1)
		(*form)->arg_fg.fg_apost = format[i];
	if ((i = ft_strichrset(format, "-")) != -1)
		(*form)->arg_fg.fg_justi = format[i];
	if ((i = ft_strichrset(format, "#")) != -1)
		(*form)->arg_fg.fg_prefi = format[i];
	if ((i = ft_strichrset(format, " ")) != -1
			&& (*form)->arg_fg.fg_signs != '+')
		(*form)->arg_fg.fg_signs = format[i];
	if ((i = ft_strichrset(format, "+")) != -1)
		(*form)->arg_fg.fg_signs = format[i];
	i = 0;
	while (format[i] && !ft_isdigit(format[i]))
		i++;
	(*form)->arg_fg.fg_zfill = (format[i++] == '0') ? 1 : -1;
	return (i);
}

int		parse_set_fg_flags(t_form *form, char *nat)
{
	form->arg_fg.type = nat[ft_strlen(nat) - 1];
	if ((ft_strichrset(nat, FLAG)) != -1)
		parse_set_fg_pad(&form, form->native_form);
	if ((ft_strichrset(nat, B_TENT)) != -1)
		parse_set_fg_wid(&form, form->native_form);
	if ((ft_strichrset(nat, PREC)) != -1)
		parse_set_fg_pre(&form, form->native_form);
	if ((ft_strichrset(nat, SIZE)) != -1)
		parse_set_fg_siz(&form, form->native_form);
	return (0);
}
