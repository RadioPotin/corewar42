/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder_opfield.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:44:23 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/15 15:01:08 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*opbyte_padding(t_token *op)
{
	t_op *optab;
	char *tmp;
	char *ret;

	tmp = NULL;
	optab = fetch_op();
	if (op->op_code == AFF)
	{
		if (!(ret = ft_itoa_baze(optab[op->op_code].code, 16)))
			return (NULL);
		return (ret);
	}
	else
	{
		if (!(tmp = ft_itoa_baze(optab[op->op_code].code, 16))
				|| !(ret = ft_strjoin("0", tmp)))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
	}
	return (ret);
}

static char		*field_with_argbyte(t_token *op)
{
	char	*binary;
	char	*hex;
	char	*opbyte;
	char	*field;

	init_fields(&binary, &hex, &opbyte, &field);
	if (!(binary = ft_itoa(get_args(op)))
			|| !(hex = ft_convert_base(binary, "01", "0123456789ABCDEF")))
	{
		ft_strdel(&binary);
		return (NULL);
	}
	else if (!(opbyte = opbyte_padding(op))
			|| !(field = ft_strjoin(opbyte, hex)))
	{
		free_fields(&binary, &hex, &opbyte, &field);
		return (NULL);
	}
	ft_strdel(&hex);
	ft_strdel(&binary);
	ft_strdel(&opbyte);
	return (field);
}

char			*generate_op(t_parser *box, t_token *op)
{
	char	*field;

	field = NULL;
	box->err = 14;
	if ((op->op_code >= LD && op->op_code <= XOR)
			|| (op->op_code >= LDI && op->op_code <= STI)
			|| (op->op_code >= LLD && op->op_code <= LLDI)
			|| op->op_code == AFF)
	{
		if (!(field = field_with_argbyte(op)))
			return (NULL);
		return (field);
	}
	else if (!(field = opbyte_padding(op)))
		return (NULL);
	return (field);
}
