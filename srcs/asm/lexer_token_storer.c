/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_storer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:14:45 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/06 10:43:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_allocator	*initialize_token_allocator(void)
{
	static t_allocator	token_allocator[15];

	if (!token_allocator[0])
	{
		token_allocator[0] = &set_label_declaration;
		token_allocator[1] = &set_label_mention;
		token_allocator[2] = &set_op_command;
		token_allocator[3] = &set_separator;
		token_allocator[4] = &set_register;
		token_allocator[5] = &set_direct_call;
		token_allocator[6] = &set_comment;
		token_allocator[7] = &set_newline;
		token_allocator[8] = &set_literal_nb;
		token_allocator[9] = &set_end;
		token_allocator[10] = &set_champ_name;
		token_allocator[11] = &set_champ_comment;
		token_allocator[12] = &set_string;
		token_allocator[13] = &set_error;
	}
	return (token_allocator);
}

static t_token		*create_new_token(t_parser *box, t_state nature,
		int *curr_i, int *curr_len)
{
	t_token		*new;
	t_allocator	*token_allocator;

	token_allocator = initialize_token_allocator();
	if (!(new = token_allocator[nature](box, curr_i, curr_len)))
		return (NULL);
	return (new);
}

static int			detect_newline_token(t_token *head)
{
	t_token		*ptr;

	ptr = head;
	while (ptr && ptr->nature != NEWLINE)
		ptr = ptr->next_token;
	if (!ptr)
		return (0);
	return (1);
}

static int			get_correct_tail(t_parser *box, t_token **ptr)
{
	t_token		*head;
	t_token		*tmp;
	t_token		*tail;

	tmp = box->code;
	head = box->code;
	while (head)
	{
		tmp = head;
		if (!detect_newline_token(tmp))
		{
			tail = tmp;
			while (tail->next_token)
				tail = tail->next_token;
			*ptr = tail;
			return (1);
		}
		else
			head = head->next_head;
	}
	*ptr = tmp;
	return (0);
}

int					token_storer(t_parser *box, t_state nature, int *curr_i,
		int *curr_len)
{
	t_token		*ptr;
	t_token		*new;

	ptr = NULL;
	if (!box->code)
	{
		if (!(new = create_new_token(box, nature, curr_i, curr_len)))
			return (asm_errout(box->err, box));
		box->code = new;
		return (1);
	}
	else
	{
		if (!(new = create_new_token(box, nature, curr_i, curr_len)))
			return (asm_errout(box->err, box));
		if (get_correct_tail(box, &ptr))
			ptr->next_token = new;
		else
			ptr->next_head = new;
	}
	return (1);
}
