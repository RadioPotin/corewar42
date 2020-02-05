/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder_argfield.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:04:21 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:02:59 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_encoder			*arg_encoder_init(void)
{
	static t_encoder tab[9];

	if (!tab[1])
	{
		tab[1] = &encode_label_mention;
		tab[4] = &encode_register;
		tab[5] = &encode_direct_call;
		tab[6] = &encode_dir_call_neg;
		tab[8] = &encode_literal_number;
	}
	return (tab);
}

static char			*argument_value_converter(t_parser *box, t_token *arg,
		int32_t field_size)
{
	char			*hex;
	char			*tmp;
	int				pad;
	t_encoder		*tab;

	tab = arg_encoder_init();
	if (!(hex = tab[arg->nature](box, arg, field_size)))
		return (NULL);
	else if ((pad = ft_strlen(hex)) < field_size)
	{
		tmp = hex;
		if (!(hex = ft_strcfill(hex, '0', 0, (field_size - pad))))
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
	}
	return (hex);
}

static char			*arg_to_bytefield(t_parser *bx, t_token *arg, char *tmp)
{
	int32_t		field_size;
	char		*conv;
	char		*format;
	char		*byte_field;

	conv = NULL;
	field_size = (arg->nature != REGISTER) ? (arg->size * 2) : 2;
	if (!(conv = argument_value_converter(bx, arg, field_size)))
		return (NULL);
	else if (!(format = ft_strcfill(conv, '|', ft_strlen(conv), 1)))
	{
		ft_strdel(&conv);
		return (NULL);
	}
	ft_strdel(&conv);
	if (!(byte_field = ft_strjoin(tmp, format)))
	{
		ft_strdel(&format);
		return (NULL);
	}
	ft_strdel(&format);
	verbose_argfield(bx, arg, byte_field);
	return (byte_field);
}

static t_token		*forward(t_token *ptr)
{
	if (ptr->nature == DIR_CALL || ptr->nature == REGISTER)
	{
		ptr = ptr->next_token->next_token;
		if (ptr->nature == SEPARATOR)
			return (ptr->next_token);
		else
			return (ptr);
	}
	else if (ptr->nature == NEWLINE || ptr->nature == END)
		return (ptr);
	if (ptr->next_token->nature == SEPARATOR)
		return (ptr->next_token->next_token);
	else
		return (ptr->next_token);
}

char				*generate_arg(t_parser *box, t_token *op)
{
	char		*arg_field;
	char		*tmp;
	t_token		*arg;

	arg_field = NULL;
	arg = op->next_token;
	while (arg && arg->nature != NEWLINE && arg->nature != END
			&& arg->nature != COMMENT)
	{
		tmp = arg_field;
		if (!(arg_field = arg_to_bytefield(box, arg, tmp)) && box->err)
		{
			ft_strdel(&tmp);
			return (NULL);
		}
		ft_strdel(&tmp);
		arg = forward(arg);
	}
	return (arg_field);
}
