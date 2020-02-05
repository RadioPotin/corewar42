/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_check_and_strlen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 12:44:31 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/14 14:53:04 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_base_check_and_strlen(char *base)
{
	int i;
	int length;

	length = 0;
	while (base[length] != '\0')
	{
		if (base[length] == '+' || base[length] == '-')
			return (0);
		i = length;
		while (i-- >= 0)
			if (base[i] == base[length])
				return (0);
		length++;
	}
	return (length);
}
