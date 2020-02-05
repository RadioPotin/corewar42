/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vac_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:26:35 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/20 16:59:04 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*c_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		wid;

	wid = (*fm)->arg_fg.fg_width;
	if (!(final = ft_strnew(1)))
		return (NULL);
	*final = (*fm)->va_holder.car;
	if (*final == '\0')
	{
		*final = '1';
		(*fm)->finfg = 1;
	}
	if ((*fm)->arg_fg.fg_width >= 2)
	{
		tmp = final;
		final = ((*fm)->arg_fg.fg_justi == '-')
			? ft_strcfill(final, ' ', 1, wid - 1)
			: ft_strcfill(final, ' ', 0, wid - 1);
		free(tmp);
	}
	return (final);
}
