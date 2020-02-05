/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:10 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:14:41 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

char	*ft_itoa_baze(uintmax_t nbr, int base)
{
	static char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F'};
	uintmax_t	n;
	intmax_t	i;
	int			converted_nbr[64];
	char		*str;

	if (nbr == 0)
		return (ft_strdup("0"));
	i = 0;
	n = nbr;
	if (n <= 0)
		return (NULL);
	while (n > 0)
	{
		converted_nbr[i++] = n % base;
		n /= base;
	}
	if (!(str = (char*)malloc(sizeof(char) * --i)))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
		str[n++] = hex[converted_nbr[i--]];
	return (str);
}
