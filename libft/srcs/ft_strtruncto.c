/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtruncto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:52:51 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/21 13:21:06 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtruncto(char *str, int preci)
{
	if (preci > 0)
		return (ft_strsub(str, 0, preci));
	else if (preci == 0)
		return (ft_strnew(1));
	return (ft_strdup(str));
}
