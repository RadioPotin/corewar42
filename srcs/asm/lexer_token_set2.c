/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_set2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:04:33 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/15 14:56:41 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*set_direct_call(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = DIR_CALL;
	new->size = DIR_SIZE;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_label_declaration(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = LABEL_DECLARATION;
	new->size = 0;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	if (hash_label_declaration(box, new) == -1)
	{
		free_token(new);
		box->err = 5;
		return (NULL);
	}
	return (new);
}

t_token		*set_label_mention(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = LABEL_MENTION;
	new->size = IND_SIZE;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_literal_nb(t_parser *box, int *curr_i, int *curr_len)
{
	t_token		*new;

	if (!(new = ft_memalloc(sizeof(t_token)))
			|| !(new->content = ft_strsub(box->file, *curr_i, *curr_len)))
	{
		free_token(new);
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = LITERAL_NB;
	new->size = IND_SIZE;
	new->relative_addr = 0;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_register(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = REGISTER;
	new->size = 1;
	*curr_i += *curr_len;
	box->curr_pos.offset += *curr_len;
	return (new);
}
