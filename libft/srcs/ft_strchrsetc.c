/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrsetc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 14:02:20 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/22 14:08:20 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_strchrsetc(char *tosearch, char *charset)
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
				return (charset[j]);
			j++;
		}
		i++;
	}
	return ('0');
}
