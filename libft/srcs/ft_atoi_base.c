/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 19:21:39 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/10 12:20:18 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_in_base(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_atoi_base(char *str, char *base)
{
	int		i;
	int		neg;
	int		nbase;
	int		value;

	i = 0;
	neg = 1;
	value = 0;
	nbase = ft_base_check_and_strlen(base);
	if (nbase <= 1)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		neg *= (str[i++] == '-' ? -1 : 1);
	while (ft_is_in_base(base, str[i]) != -1)
	{
		value = value * nbase + ft_is_in_base(base, str[i]);
		i++;
	}
	if (!str[i] || str[i] == '-' || str[i] == '+')
		return (neg * value);
	else
		return (0);
}
