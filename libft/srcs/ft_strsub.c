/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evogel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:35:44 by evogel            #+#    #+#             */
/*   Updated: 2019/02/04 15:46:15 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s1 == NULL || !(sub = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len && s1)
		sub[i++] = s1[start++];
	sub[i] = '\0';
	return (sub);
}
