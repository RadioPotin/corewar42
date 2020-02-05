/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umaxt_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:37:59 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/18 13:11:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uintmax_t	rec_sizer(uintmax_t nb, int fg_negative, uintmax_t ret)
{
	if (nb == 0 && fg_negative == 1)
		return (ret + 1);
	else if (nb == 0 && fg_negative <= 0)
		return (ret);
	return (rec_sizer(nb / 10, fg_negative, ret + 1));
}

static char			*zerocase(int fg_negative)
{
	char	*itoa;

	itoa = NULL;
	if (fg_negative == 1)
	{
		itoa = ft_strnew(2);
		itoa[0] = '-';
		itoa[1] = '0';
		return (itoa);
	}
	else if (fg_negative == 0)
	{
		itoa = ft_strnew(1);
		itoa[0] = '0';
		return (itoa);
	}
	return (NULL);
}

char				*uintmaxt_itoa(uintmax_t nb, int fg_negative)
{
	char	*itoa;
	int		len;

	len = rec_sizer(nb, fg_negative, 0);
	itoa = NULL;
	if (nb == 0)
	{
		itoa = zerocase(fg_negative);
		return (itoa);
	}
	if (fg_negative == 1)
		len++;
	if (!(itoa = ft_strnew(len)))
		return (NULL);
	if (fg_negative == 1)
	{
		itoa[0] = '-';
		len--;
	}
	while (len >= 0 && nb != 0)
	{
		itoa[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoa);
}
