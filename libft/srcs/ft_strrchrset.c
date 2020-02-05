/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 10:51:04 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/28 17:01:16 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchrset(char *tosearch, char *charset)
{
	int i;
	int j;

	if (tosearch && charset)
	{
		i = ft_strlen(tosearch);
		while (i >= 0)
		{
			j = 0;
			while (charset[j])
			{
				if (tosearch[i] == charset[j])
					return (&tosearch[i]);
				j++;
			}
			i--;
		}
	}
	return (NULL);
}
