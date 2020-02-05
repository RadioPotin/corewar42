/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:19:07 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/03 12:18:48 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/*
** Negative HEXES FALSE
*/

static int	malloc_size(long nbr, int base)
{
	int i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(long nb, int base)
{
	int		neg;
	int		size;
	char	*o_base;
	char	*a;
	int		index;

	index = 0;
	neg = 0;
	o_base = "0123456789ABCDEF";
	if (nb < 0)
		neg = 1;
	nb *= (nb < 0 ? -1 : 1);
	size = malloc_size(nb, base) + neg;
	if (!(a = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (nb != 0)
	{
		a[index++] = o_base[nb % base];
		nb /= base;
	}
	if (neg)
		a[index] = '-';
	a[size + 1] = '\0';
	return (ft_strrev(a));
}
