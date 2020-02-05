/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder_argument.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:03:54 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:01:36 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*encode_register(t_parser *box, t_token *arg, int32_t size)
{
	char *hex;

	if (!(hex = ft_convert_base(arg->next_token->content, "0123456789",
					"0123456789ABCDEF")))
		return (NULL);
	else if (ft_strlen(hex) > (size_t)size)
	{
		box->err = 15;
		box->curr_pos = arg->location;
		ft_strdel(&hex);
		return (NULL);
	}
	return (hex);
}

char				*encode_literal_number(t_parser *b, t_token *a, int32_t si)
{
	char *nb;
	char *hex;

	hex = NULL;
	nb = a->content;
	if (convert_nb_to_hex(nb, &hex) == -1)
	{
		b->err = 16;
		return (NULL);
	}
	else if (ft_strlen(hex) > (size_t)si)
	{
		b->err = 15;
		b->curr_pos = a->location;
		ft_strdel(&hex);
		return (NULL);
	}
	return (hex);
}

char				*encode_label_mention(t_parser *b, t_token *ar, int32_t si)
{
	char *nb;
	char *hex;

	hex = NULL;
	if (!(nb = ft_itoa(ar->relative_addr)))
		return (NULL);
	else if (convert_nb_to_hex(nb, &hex) == -1)
	{
		ft_strdel(&nb);
		b->err = 16;
		return (NULL);
	}
	else if (ft_strlen(hex) > (size_t)si)
	{
		b->err = 15;
		b->curr_pos = ar->location;
		ft_strdel(&hex);
		ft_strdel(&nb);
		return (NULL);
	}
	ft_strdel(&nb);
	return (hex);
}

char				*encode_dir_call_neg(t_parser *b, t_token *a, int32_t siz)
{
	char *nb;
	char *hex;

	hex = NULL;
	nb = a->content;
	if (convert_dirneg_to_hex(nb, &hex) == -1)
	{
		b->err = 16;
		return (NULL);
	}
	else if (ft_strlen(hex) > (size_t)siz * 2)
	{
		b->err = 15;
		b->curr_pos = a->location;
		ft_strdel(&hex);
		return (NULL);
	}
	return (hex);
}

char				*encode_direct_call(t_parser *b, t_token *arg, int32_t siz)
{
	t_encoder	*tab;
	int			i;
	char		*hex;

	tab = arg_encoder_init();
	i = dispatch_encoder(arg->next_token, siz);
	if (!(hex = tab[i](b, arg->next_token, siz)))
		return (NULL);
	else if (i != 6 && ft_strlen(hex) > (size_t)siz)
	{
		b->err = 15;
		b->curr_pos = arg->location;
		ft_strdel(&hex);
		return (NULL);
	}
	return (hex);
}
