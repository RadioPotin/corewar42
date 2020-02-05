/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:51:16 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 10:47:26 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcfill(const char *str, char chr, long int index,
		long int len)
{
	char		*ret;
	long int	i;
	long int	size;

	i = 0;
	size = len + ft_strlen(str);
	if (!str || len < 0 || !(ret = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		if (i == index && len != 0)
		{
			while (len > 0)
			{
				ret[index++] = chr;
				len--;
			}
			while (str[i] && index < size)
				ret[index++] = str[i++];
			return (ret);
		}
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
