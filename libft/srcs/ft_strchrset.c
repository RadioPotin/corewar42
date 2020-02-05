/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:56:48 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/22 16:58:10 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrset(char *tosearch, char *charset)
{
	int i;
	int j;

	i = 0;
	while (tosearch[i])
	{
		j = 0;
		while (charset[j])
		{
			if (tosearch[i] == charset[j])
				return (&charset[j]);
			j++;
		}
		i++;
	}
	return (NULL);
}
