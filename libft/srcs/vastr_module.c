/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vastr_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 16:31:11 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/21 18:50:25 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		len;
	int		wid;

	if ((*fm)->va_holder.str == NULL)
		final = ft_strtruncto("(null)", (*fm)->arg_fg.fg_preci);
	else
		final = ft_strtruncto((*fm)->va_holder.str, (*fm)->arg_fg.fg_preci);
	wid = (*fm)->arg_fg.fg_width;
	len = ft_strlen(final);
	if (wid > len)
	{
		tmp = final;
		final = ((*fm)->arg_fg.fg_justi == '-')
			? ft_strcfill(final, ' ', len, wid - len)
			: ft_strcfill(final, ' ', 0, wid - len);
		free(tmp);
	}
	return (final);
}
