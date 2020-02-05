/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_players.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:57:41 by gjuste            #+#    #+#             */
/*   Updated: 2020/01/13 19:55:01 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	get_opt(t_cw *cw, char **av, int ac, int *i)
{
	while (*i < ac - 1 && av[*i][0] == '-')
	{
		if (*i >= ac - 1)
			return (-1);
		if (ft_strcmp(av[*i], "-dump") == 0 && cw->dump == -1)
		{
			if ((cw->dump = ft_atoi(av[++*i])) == 0)
				return (-1);
		}
		else if (ft_strcmp(av[*i], "-cl") == 0 && !cw->cl)
			cw->cl++;
		else if (ft_strcmp(av[*i], "-cp") == 0 && !cw->cp)
			cw->cp++;
		else if (ft_strcmp(av[*i], "-nl") == 0 && !cw->no_live)
			cw->no_live++;
		else
			return (ft_strcmp(av[*i], "-n") == 0 ? 0 : -1);
		(*i)++;
	}
	return (0);
}

static int	get_nb(t_cw *cw, char **av, int ac, int *i)
{
	if (*i >= ac - 1)
		return (-1);
	if (ft_strcmp(av[*i], "-n") == 0)
	{
		if ((cw->tmp_nb_p = ft_atoi(av[++*i])) == 0)
			return (-1);
		if ((get_champ(cw, av, ac, ++*i) == -1))
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int			read_players(t_cw *cw, int ac, char **av)
{
	int i;

	i = 1;
	if (ac <= 1)
		return (-1);
	if (av[i][0] == '-' && ft_strcmp(av[i], "-n") != 0)
		if (get_opt(cw, av, ac, &i) == -1)
			return (-1);
	while (i < ac && cw->players != 4)
	{
		if (av[i][0] == '-')
		{
			if ((get_nb(cw, av, ac, &i) == -1))
				return (-1);
		}
		else if (i >= ac || get_champ(cw, av, ac, i) == -1)
			return (-1);
		i++;
	}
	return (i < ac ? -1 : 0);
}
