/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:22:59 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 10:43:22 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		rec_conv(char *nb, char *nativebase, int base, uintmax_t *ret)
{
	int i;

	i = 0;
	if (*nb != '\0')
	{
		while (nativebase[i] != *nb)
			i++;
		*ret = (*ret * base) + i;
		rec_conv(nb + 1, nativebase, base, ret);
	}
	return ;
}

uintmax_t		ft_atoull_base(char *nb, char *nativebase)
{
	uintmax_t	ret;
	int			base;

	ret = 0;
	base = ft_strlen(nativebase);
	if (!nb || !*nb)
		return (0);
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (ft_isdigit(*nb))
		rec_conv(nb, nativebase, base, &ret);
	return (ret);
}
