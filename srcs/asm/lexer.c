/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 12:17:15 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/15 12:31:16 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_tokenizer	*token_thesaurus(void)
{
	static t_tokenizer tab[13];

	if (tab[0] == NULL)
	{
		tab[0] = &is_label_declaration;
		tab[1] = &is_label_mention;
		tab[2] = &is_op_command;
		tab[3] = &is_separator;
		tab[4] = &is_register;
		tab[5] = &is_direct_call;
		tab[6] = &is_comment;
		tab[7] = &is_newline;
		tab[8] = &is_literal_nb;
		tab[9] = &is_end;
		tab[10] = &is_champ_name;
		tab[11] = &is_champ_comment;
		tab[12] = &is_string;
	}
	return (tab);
}

static t_state		tokenizer(char *s, int *current, int *len_of_token)
{
	t_tokenizer		*tokenizer;
	int				i;

	i = 0;
	tokenizer = token_thesaurus();
	while (i < 13)
	{
		if (tokenizer[i](&s[*current], len_of_token))
			return (i);
		i++;
	}
	return (ERROR);
}

static void			skip_whitespaces(char *s, int *i, t_pos *curr_pos)
{
	while (s[*i] && s[*i] != '\n' && (s[*i] == ' ' || s[*i] == '\t'
				|| s[*i] == '\r'))
	{
		*i += 1;
		curr_pos->offset++;
	}
}

int					lexer(t_parser *box)
{
	int			i;
	int			len;
	t_state		nature;

	i = 1;
	len = 0;
	nature = START;
	box->curr_pos.line = 1;
	while (nature != ERROR && nature != END)
	{
		skip_whitespaces(box->file, &i, &box->curr_pos);
		if ((nature = tokenizer(box->file, &i, &len)) == ERROR)
			return (asm_errout(6, box));
		if (token_storer(box, nature, &i, &len) == -1)
			return (-1);
		len = 0;
	}
	return (0);
}
