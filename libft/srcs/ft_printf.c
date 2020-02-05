/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 15:01:38 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/22 12:29:56 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		formnaturecheck(const char *ptr)
{
	return (ft_nchrchck(ptr + 1, OPT, ft_strichrset(ptr, CONVTYPE)));
}

static int		buff_feeder(const char *ptr, size_t size, va_list arg)
{
	int		len;
	int		no;
	size_t	i;

	i = 0;
	no = 0;
	while (ptr[i] && i < size)
	{
		while (ptr[i] && ptr[i] == '%' && isprcnt(&ptr[i]) == 1
				&& (no += prct(&ptr[i])) >= 0)
			i += iupdate(&ptr[i]);
		while (ptr[i] && ptr[i] == '%')
		{
			len = formnaturecheck(&ptr[i]);
			i += (len == -1) ? ft_nonchrseti(&ptr[i + 1], OPT) : 0;
			if (len == -1 || len == 0)
				break ;
			no += check_set_form(&ptr[i], arg);
			i += len + 1;
		}
		no += securebuffer(ptr[i++]);
	}
	no += *g_buff ? buff_print() : 0;
	return (no);
}

int				ft_printf(const char *template, ...)
{
	va_list			arg;
	int				no;
	size_t			len;

	va_start(arg, template);
	init_gvars();
	if (template == NULL)
		return (-1);
	len = ft_strlen(template);
	if ((no = buff_feeder(template, len, arg)) == -1)
		return (-1);
	va_end(arg);
	return (no);
}
