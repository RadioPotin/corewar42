/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_pad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:13:07 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 14:27:14 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*clean_pad(char *fin, char c, unsigned int i, int len)
{
	char	*ret;

	ret = fin;
	fin = ft_strcfill(fin, c, i, len);
	ft_strdel(&ret);
	return (fin);
}
