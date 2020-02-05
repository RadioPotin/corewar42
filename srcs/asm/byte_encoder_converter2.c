/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder_converter2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:59:58 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:00:28 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	add_unit_(int *i, char **bin, char **conv)
{
	while (--(*i) != -1)
	{
		if ((*bin)[*i] == '1')
			(*bin)[*i] = '0';
		else if ((*bin)[*i] == '0')
		{
			(*bin)[*i] = '1';
			break ;
		}
	}
	*conv = *bin;
	return (0);
}

static int	invert_bin(char **conv)
{
	int		i;
	int		pad;
	char	*bin;
	char	*tmp;

	i = -1;
	bin = *conv;
	if ((pad = ft_strlen(*conv)) < 32)
	{
		if (!(bin = ft_strcfill(*conv, '0', 0, 32 - pad)))
			return (-1);
		ft_strdel(conv);
	}
	while (bin[++i])
		bin[i] = (bin[i] == '0') ? '1' : '0';
	add_unit_(&i, &bin, conv);
	if (i == -1)
	{
		if (!(tmp = ft_strjoin("1", bin)))
			return (-1);
		ft_strdel(conv);
		*conv = tmp;
		return (1);
	}
	return (1);
}

int			convert_dirneg_to_hex(char *nb, char **hex)
{
	char	*conv;

	if (*nb == '-')
	{
		if (!(conv = ft_convert_base(&nb[1], "0123456789", "01"))
				|| invert_bin(&conv) == -1)
		{
			ft_strdel(&conv);
			return (-1);
		}
		else if (!(*hex = ft_convert_base(conv, "01", "0123456789ABCDEF")))
		{
			ft_strdel(&conv);
			return (-1);
		}
		ft_strdel(&conv);
		return (1);
	}
	else if (!(*hex = ft_convert_base(nb, "0123456789", "0123456789ABCDEF")))
		return (-1);
	return (1);
}

int			dispatch_encoder(t_token *arg, int32_t size)
{
	if (arg->nature != LITERAL_NB || size < 8)
		return (arg->nature);
	return (6);
}
