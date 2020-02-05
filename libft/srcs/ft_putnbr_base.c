/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:22:10 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/03 12:47:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_base(int nbr, char *base)
{
	int		nbase;

	nbase = ft_base_check_and_strlen(base);
	if (nbase > 1)
	{
		if (nbr == -2147483648)
		{
			ft_putchar('-');
			ft_putnbr_base(-1 * (nbr / nbase), base);
			ft_putchar(base[-1 * (nbr % nbase)]);
		}
		else if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
			ft_putnbr_base(nbr, base);
		}
		else if (nbr >= nbase)
		{
			ft_putnbr_base(nbr / nbase, base);
			ft_putnbr_base(nbr % nbase, base);
		}
		else
			ft_putchar(base[nbr]);
	}
}
