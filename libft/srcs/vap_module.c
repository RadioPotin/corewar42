/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vap_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:26:35 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/20 10:36:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*precundefinedbehaviour(char *fin, t_form *fm, int len)
{
	char *mod;

	mod = fin;
	if (fm->arg_fg.fg_preci == 0 && fm->va_holder.vptr == 0)
	{
		free(fin);
		return (ft_strnew(1));
	}
	if (len - fm->arg_fg.fg_preci < 0)
		fin = ft_strcfill(mod, '0', 0, fm->arg_fg.fg_preci - len);
	else
		return (fin);
	ft_strdel(&mod);
	return (fin);
}

char			*p_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		len;

	final = uintmaxt_itoa((uintptr_t)(*fm)->va_holder.vptr, 0);
	tmp = final;
	final = ft_convert_base(tmp, B_TENT, B_HEXL);
	ft_strdel(&tmp);
	tmp = final;
	if ((*fm)->arg_fg.fg_preci >= 0)
		final = precundefinedbehaviour(tmp, *fm, ft_strlen(tmp));
	tmp = final;
	final = ft_strsfill(tmp, "0x", 0);
	free(tmp);
	len = ft_strlen(final);
	if ((*fm)->arg_fg.fg_width > len)
	{
		tmp = final;
		final = ((*fm)->arg_fg.fg_justi == '-')
			? ft_strcfill(final, ' ', len, (*fm)->arg_fg.fg_width - len)
			: ft_strcfill(final, ' ', 0, (*fm)->arg_fg.fg_width - len);
		free(tmp);
	}
	return (final);
}
