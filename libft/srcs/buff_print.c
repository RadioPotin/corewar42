/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 10:22:02 by dapinto           #+#    #+#             */
/*   Updated: 2019/05/29 13:35:32 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		nullcharprint(char *fin)
{
	int		char_nbr;
	char	c;
	char	*ptr;

	c = '\0';
	char_nbr = buff_print();
	char_nbr += ft_strlen(fin);
	ptr = ft_strchr(fin, '1');
	write(1, fin, ft_strichr(fin, '1'));
	write(1, &c, 1);
	write(1, ptr + 1, ft_strlen(ptr + 1));
	g_buffi = 0;
	free(fin);
	fin = NULL;
	return (char_nbr);
}

int				buff_print(void)
{
	int				char_nbr;
	unsigned int	i;

	i = 0;
	char_nbr = ft_strlen(g_buff);
	ft_putstr(g_buff);
	while (g_buff[i])
		g_buff[i++] = '\0';
	g_buffi = 0;
	return (char_nbr);
}

int				print_flush(char *form)
{
	int		char_nbr;

	char_nbr = buff_print();
	char_nbr += ft_strlen(form);
	ft_putstr(form);
	free(form);
	form = NULL;
	return (char_nbr);
}

int				securebuffer(char c)
{
	int o;

	if (g_buffi < BUFFSIZE)
	{
		g_buff[g_buffi++] = c;
		return (0);
	}
	else if (g_buffi == BUFFSIZE)
	{
		o = buff_print();
		g_buff[g_buffi++] = c;
		return (o);
	}
	return (-1);
}

int				print_dispatch(t_form *fm)
{
	if (fm->finfg == 1)
		return (nullcharprint(fm->final_form));
	else
		return (print_flush(fm->final_form));
	return (-1);
}
