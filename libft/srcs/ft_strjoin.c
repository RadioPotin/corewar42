/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 07:59:56 by dapinto           #+#    #+#             */
/*   Updated: 2019/08/06 14:00:54 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_concat_all(char *dest, char const *s1, char const *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!dest)
		return (NULL);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	while (s2[i])
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	dest = NULL;
	if (!s1 && !s2)
		return (dest);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!(dest = malloc(sizeof(char) * len)))
		return (NULL);
	ft_concat_all(dest, s1, s2);
	return (dest);
}
