/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_token3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:57:46 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 11:38:03 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		search_op_manuel(char *s, t_op *op)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(s, op[i].name))
			return (1);
		i++;
	}
	return (0);
}

static int		get_end_op(char *s)
{
	int i;

	i = 0;
	while (s[i] && is_alphabet_char(s[i], OP_ALPHABET))
		i++;
	return (i);
}

int				is_op_command(char *s, int *len)
{
	t_op	*op;
	char	curr_op[6];
	int		op_end_i;

	op = fetch_op();
	op_end_i = get_end_op(s);
	ft_bzero(&curr_op, sizeof(char) * 5);
	if (op_end_i && op_end_i >= 2 && op_end_i <= 5)
	{
		if (is_alphabet_char(*s, OP_ALPHABET))
			ft_strncpy(curr_op, s, op_end_i);
		else
			return (0);
	}
	if (search_op_manuel(curr_op, op))
	{
		*len = op_end_i;
		return (1);
	}
	return (0);
}

static int		count_digits(char *s)
{
	int i;

	i = 0;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	return (i);
}

int				is_register(char *s, int *len)
{
	int i;
	int ret;

	i = 1;
	if (*s == 'r' && ((ret = count_digits(&s[i])) == 1 || ret == 2))
	{
		*len = i;
		return (1);
	}
	return (0);
}
