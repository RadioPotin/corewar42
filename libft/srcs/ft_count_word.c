/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 09:20:41 by dapinto           #+#    #+#             */
/*   Updated: 2019/08/07 09:23:11 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(char const *s, char c)
{
	int		count;
	int		i;
	int		bol;

	count = 0;
	i = 0;
	bol = 1;
	while (s[i])
	{
		if (s[i] == c)
			bol = 1;
		else if (bol == 1)
		{
			count++;
			bol = 0;
		}
		i++;
	}
	return (count);
}
