/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:42:09 by dapinto           #+#    #+#             */
/*   Updated: 2019/02/13 10:45:18 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_freer(char **tofree, char *tolink)
{
	if (*tofree != NULL)
	{
		free(*tofree);
		*tofree = NULL;
	}
	return (tolink);
}
