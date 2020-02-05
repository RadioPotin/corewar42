/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_set3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:06:46 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:34:30 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_op_e	identify_op(t_parser *box, int i, int len)
{
	t_op	*opman;
	int		index;
	char	*op;

	index = 0;
	opman = fetch_op();
	if (!(op = ft_strsub(box->file, i, len)))
		return (MALERROR);
	while (index < 16)
	{
		if (!ft_strcmp(opman[index].name, op))
		{
			ft_strdel(&op);
			return (index);
		}
		index++;
	}
	return (ERR);
}

t_token			*set_op_command(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token)))
			|| !(new->content = ft_strsub(box->file, *curr_i, *curr_len)))
	{
		free_token(new);
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = OP_CMD;
	if ((new->op_code = identify_op(box, *curr_i, *curr_len)) == MALERROR)
	{
		box->err = 1;
		ft_strdel(&new->content);
		free(new);
		return (NULL);
	}
	else if (new->op_code == ERR)
		new->nature = ERROR;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}

t_token			*set_champ_name(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token)))
			|| !(new->content = ft_strsub(box->file, *curr_i, *curr_len)))
	{
		free_token(new);
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = CHAMP_NAME;
	new->size = ft_strlen(new->content);
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	box->champ_name = new;
	return (new);
}

t_token			*set_champ_comment(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token)))
			|| !(new->content = ft_strsub(box->file, *curr_i, *curr_len)))
	{
		free_token(new);
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = CHAMP_COMMENT;
	new->size = ft_strlen(new->content);
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	box->champ_comment = new;
	return (new);
}

t_token			*set_string(t_parser *box, int *c_i, int *c_l)
{
	t_token		*new;
	int			i;

	i = 0;
	if (!(new = ft_memalloc(sizeof(t_token)))
			|| !(new->content = ft_strsub(box->file, (*c_i + 1), (*c_l - 2))))
	{
		free_token(new);
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = STRING;
	new->size = ft_strlen(new->content);
	while (new->content[i])
	{
		if (new->content[i] == '\n' && (box->curr_pos.offset = -1))
			box->curr_pos.line++;
		box->curr_pos.offset++;
		i++;
	}
	*c_i += *c_l;
	return (new);
}
