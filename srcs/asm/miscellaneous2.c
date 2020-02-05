/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:47:42 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/12 13:59:52 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		ft_is_in_base(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int				ft_byte_base(int *str, char *base)
{
	int		i;
	int		neg;
	int		nbase;
	int		value;

	i = 0;
	neg = 1;
	value = 0;
	nbase = ft_base_check_and_strlen(base);
	if (nbase <= 1)
		return (0);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
		neg *= (str[i++] == '-' ? -1 : 1);
	while (ft_is_in_base(base, str[i]) != -1)
	{
		value = value * nbase + ft_is_in_base(base, str[i]);
		i++;
	}
	if (!str[i] || str[i] == '-' || str[i] == '+')
		return (neg * value);
	else
		return (0);
}

void			free_fields_exe(int **tmp, int **code)
{
	if (*tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (*code)
	{
		free(*code);
		*code = NULL;
	}
}

int				init_bytes_to_write(t_parser **box)
{
	if (!((*box)->bytes_to_write = ft_memalloc(sizeof(int) *
					(*box)->code_size)))
		return (0);
	ft_bzero((*box)->bytes_to_write, sizeof(int) * (*box)->code_size);
	return (1);
}

char			*give_op(int nature)
{
	static char		*op_tab[18];

	if (!op_tab[0])
	{
		op_tab[0] = "LIVE";
		op_tab[1] = "LD";
		op_tab[2] = "ST";
		op_tab[3] = "ADD";
		op_tab[4] = "SUB";
		op_tab[5] = "AND";
		op_tab[6] = "OR";
		op_tab[7] = "XOR";
		op_tab[8] = "ZJMP";
		op_tab[9] = "LDI";
		op_tab[10] = "STI";
		op_tab[11] = "FORK";
		op_tab[12] = "LLD";
		op_tab[13] = "LLDI";
		op_tab[14] = "LFORK";
		op_tab[15] = "AFF";
		op_tab[16] = "ERR";
		op_tab[17] = "MALERROR";
	}
	return (ft_strdup(op_tab[nature]));
}
