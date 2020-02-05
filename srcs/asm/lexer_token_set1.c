/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_set1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:01:49 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/03 15:26:39 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_token		*set_comment(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = COMMENT;
	new->size = 0;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_end(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token))))
	{
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = END;
	new->size = 0;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_error(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token))))
	{
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = ERROR;
	new->size = 0;
	*curr_i += *curr_len;
	box->err = 6;
	return (new);
}

t_token		*set_newline(t_parser *box, int *curr_i, int *curr_len)
{
	t_token *new;

	if (!(new = ft_memalloc(sizeof(t_token))))
	{
		box->err = 1;
		return (NULL);
	}
	new->location = box->curr_pos;
	new->nature = NEWLINE;
	new->size = 0;
	box->curr_pos.line += 1;
	box->curr_pos.offset = 0;
	*curr_i += *curr_len;
	return (new);
}

t_token		*set_separator(t_parser *box, int *curr_i, int *curr_len)
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
	new->nature = SEPARATOR;
	new->size = 0;
	box->curr_pos.offset += *curr_len;
	*curr_i += *curr_len;
	return (new);
}
