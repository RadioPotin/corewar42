/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder_converter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:23:48 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/16 11:59:24 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>

int			extract_byte(t_parser *box, int *byte, char **str, int range)
{
	int i;

	i = 0;
	if (!(*str)[i] || range == 0)
		return (0);
	box->bytes_to_write[box->arg_index++] = range * 0.5;
	while (i < range)
	{
		byte[i] = (*str)[i];
		i++;
	}
	*str += ((*str)[i] && (*str)[i] == '|') ? i + 1 : i;
	return (1);
}

int			string_to_bytefield(char **dest, char *src, size_t bytes)
{
	unsigned int	i;

	i = 0;
	if (!(*dest = ft_strnew(sizeof(char) * (bytes + 1))))
		return (-1);
	while (src[i] && i < bytes)
	{
		(*dest)[i] = src[i];
		i++;
	}
	if (i < bytes)
		ft_memset(&(*dest)[i], '\0', (bytes - i));
	return (1);
}

static int	add_unit(int *i, char **bin, char **conv)
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

static int	invert_binary(char **conv)
{
	int		i;
	int		pad;
	char	*bin;
	char	*tmp;

	i = -1;
	bin = *conv;
	if ((pad = ft_strlen(*conv)) < 16)
	{
		if (!(bin = ft_strcfill(*conv, '0', 0, 16 - pad)))
			return (-1);
		ft_strdel(conv);
	}
	while (bin[++i])
		bin[i] = (bin[i] == '0') ? '1' : '0';
	add_unit(&i, &bin, conv);
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

int			convert_nb_to_hex(char *nb, char **hex)
{
	char	*conv;

	if (*nb == '-')
	{
		if (!(conv = ft_convert_base(&nb[1], "0123456789", "01"))
				|| invert_binary(&conv) == -1)
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
