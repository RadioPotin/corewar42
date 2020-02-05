/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentmanager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 13:49:02 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/06 10:59:07 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		tmpfgset(t_flags *fg, const char *ptr)
{
	int i;

	i = 0;
	while (!ft_isdigit(ptr[i]))
	{
		if (ptr[i] == '-')
			fg->fg_justi = '-';
		if (ptr[i] == '.')
			return ;
		i++;
	}
	while (ptr[i] == '0')
	{
		fg->fg_zfill = 1;
		i++;
	}
	if (ptr[i] != '0' && ft_isdigit(ptr[i]))
	{
		fg->fg_width = ft_atoi(&ptr[i]);
		return ;
	}
}

static char		*percentrenderer(t_flags fg)
{
	char *tmp;

	tmp = ft_strnew(2);
	*tmp = '%';
	if (fg.fg_width > -1)
	{
		if ((fg.fg_justi == '-' && fg.fg_zfill == 1)
				|| (fg.fg_justi == '-' && fg.fg_zfill == -1))
			tmp = clean_pad(tmp, ' ', 1, fg.fg_width - 1);
		if (fg.fg_justi != '-' && fg.fg_zfill == -1)
			tmp = clean_pad(tmp, ' ', 0, fg.fg_width - 1);
		if (fg.fg_justi != '-' && fg.fg_zfill == 1)
			tmp = clean_pad(tmp, '0', 0, fg.fg_width - 1);
	}
	return (tmp);
}

int				isprcnt(const char *ptr)
{
	int i;
	int len;

	i = 0;
	len = ft_nchrchck(&ptr[i], PRCNT, ft_strichr(&ptr[i + 1], '%') + 1);
	if (len >= 0 || ptr[1] == '%')
		return (1);
	return (0);
}

int				iupdate(const char *ptr)
{
	int i;

	i = 0;
	if (ptr[i] == '%' && ptr[1] == '%')
		return (2);
	else if (ft_nchrchck(&ptr[i], PRCNT, ft_strichrset(&ptr[i], "%")) != -1)
		return (ft_strichr(&ptr[i + 1], '%') + 2);
	return (0);
}

int				prct(const char *ptr)
{
	int		i;
	int		len;
	char	*tmp;
	t_flags	fg;

	i = 0;
	if (ptr[i] == '%' && ptr[i + 1] == '%')
	{
		tmp = ft_strnew(1);
		*tmp = '%';
		return (print_flush(tmp));
	}
	else if (ft_nchrchck(&ptr[i], PRCNT, ft_strichrset(&ptr[i], "%")) != -1)
	{
		init_fg(&fg);
		tmpfgset(&fg, ptr);
		tmp = percentrenderer(fg);
		len = print_flush(tmp);
		return (len);
	}
	return (0);
}
