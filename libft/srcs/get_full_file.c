/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_full_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 12:32:54 by dapinto           #+#    #+#             */
/*   Updated: 2019/10/01 17:45:08 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*concatenate_and_feed(char **dest, char **src)
{
	char *ret;
	char *tmp;

	if (!(tmp = ft_strjoin(*dest, *src)))
	{
		ft_strdel(dest);
		ft_strdel(src);
		return (NULL);
	}
	if (!(ret = ft_strcfill(tmp, '\n', ft_strlen(*dest), 1)))
	{
		ft_strdel(dest);
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_strdel(dest);
	ft_strdel(&tmp);
	ft_strdel(src);
	return (ret);
}

char			*get_full_file(int fd)
{
	char	*ret;
	char	*tmp;
	char	*line;
	int		rd;

	ret = NULL;
	line = NULL;
	rd = 1;
	if (fd < 0)
		return (ret);
	while (rd == 1)
	{
		tmp = ret;
		rd = get_next_line(fd, &line);
		if ((rd == 0 || rd == 1) && (ret = concatenate_and_feed(&tmp, &line)))
			;
		else if (ret == NULL || (rd != 0 && rd != 1))
			ft_strdel(&ret);
	}
	ft_strdel(&line);
	return (ret);
}
