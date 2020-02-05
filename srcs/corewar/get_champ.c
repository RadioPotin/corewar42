/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 11:18:35 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/14 19:21:23 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	ft_read_it(t_cw *cw, t_play *pl, char *name)
{
	int				ret;
	int				fd;
	int				iter;
	char			line[1024];

	ret = 1;
	iter = 0;
	if ((fd = open(name, O_RDONLY)) < 0)
		return (-1);
	ft_bzero(line, 1024);
	while ((ret = read(fd, line, 1024)) > 0)
	{
		if (!(pl->champ = (char*)realloc(pl->champ, iter * 1024 + ret)))
		{
			ft_strdel(&pl->champ);
			return (-1);
		}
		ft_memcpy(pl->champ + iter * 1024, line, ret);
		ft_bzero(line, 1024);
		pl->size = iter * 1024 + ret;
		iter++;
	}
	close(fd);
	cw->error = pl->size < 2192 ? 5 : cw->error;
	return (ret < 0 || pl->size < 2192 ? -1 : 0);
}

static int	check_player(t_cw *cw, t_play *pl)
{
	if (!pl->name[0])
	{
		cw->error = 1;
		return (-1);
	}
	else if (!pl->comment[0])
	{
		cw->error = 2;
		return (-1);
	}
	return (0);
}

static int	ft_readchamp(t_cw *cw, t_play *pl, char *name)
{
	unsigned char	nb[4];

	if (ft_read_it(cw, pl, name) == -1 || check_binairy(cw, pl->champ) == -1)
		return (-1);
	ft_memcpy(pl->name, pl->champ + 4, 129);
	ft_memcpy(pl->comment, pl->champ + 140, 2049);
	ft_memcpy(nb, pl->champ + 136, 4);
	if (check_player(cw, pl) == -1)
		return (-1);
	pl->c_size = nb[3] + 256 * nb[2] + 65536 * nb[1] + 16777216 * nb[0];
	cw->players++;
	if (pl->c_size != pl->size - 2192)
	{
		cw->error = 4;
		return (-1);
	}
	if (create_process(cw, pl) == -1)
	{
		cw->error = 6;
		return (-1);
	}
	return (0);
}

static int	check_nb_p(t_cw *cw, int check)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (cw->player[i].number == check)
			return (-1);
		i++;
	}
	return (0);
}

int			get_champ(t_cw *cw, char **av, int ac, int i)
{
	int j;
	int player;

	player = 1;
	j = 0;
	if (i >= ac)
		return (-1);
	while (j < 4 && cw->player[j].number != 0)
	{
		j++;
		if (check_nb_p(cw, player) == -1)
			player++;
	}
	if (check_nb_p(cw, cw->tmp_nb_p ? cw->tmp_nb_p : player) == -1)
		return (-1);
	cw->player[j].number = cw->tmp_nb_p ? cw->tmp_nb_p : player;
	cw->tmp_nb_p = 0;
	if (ft_readchamp(cw, &cw->player[j], av[i]) == -1)
		return (-1);
	return (0);
}
