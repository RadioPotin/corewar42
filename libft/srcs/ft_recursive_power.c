/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:37:20 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 11:29:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uintmax_t		ft_recursive_power(uintmax_t nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
	{
		nb *= ft_recursive_power(nb, power - 1);
	}
	return (nb);
}
