/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:18:03 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 10:46:19 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		conv(uintmax_t nb, char *base, int id, char *buf)
{
	if (nb == 0 && id == 0)
	{
		buf[0] = base[0];
		buf[1] = '\0';
		return ;
	}
	if (nb > 0)
	{
		conv(nb / ft_strlen(base), base, id + 1, buf);
		buf[id] = base[nb % ft_strlen(base)];
		return ;
	}
	buf[id] = '\0';
	return ;
}

static char		*convert(char *nbr, char *base_from, char *base_to)
{
	char		buffer[64];
	char		*convarray;
	uintmax_t	base_ten;
	int			buff_len;
	int			i;

	i = 0;
	base_ten = ft_atoull_base(nbr, base_from);
	conv(base_ten, base_to, i, buffer);
	buff_len = ft_strlen(buffer);
	if (!(convarray = ft_strnew(buff_len)))
		return (NULL);
	while (buff_len >= 0)
		convarray[i++] = buffer[--buff_len];
	convarray[i - 1] = '\0';
	return (convarray);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*negative;
	char	*tmp;

	if (nbr[0] == '-')
	{
		nbr += 1;
		negative = convert(nbr, base_from, base_to);
		tmp = negative;
		negative = ft_strcfill(negative, '-', 0, 1);
		free(tmp);
		return (negative);
	}
	else
		return (convert(nbr, base_from, base_to));
}
