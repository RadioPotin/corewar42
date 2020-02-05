/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:32:01 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/07 17:36:10 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_verbose	*verboser(void)
{
	static t_verbose	verbose_tab[14];

	if (!verbose_tab[1])
	{
		verbose_tab[0] = &verbose_label_declaration;
		verbose_tab[1] = &verbose_label_mention;
		verbose_tab[2] = &verbose_op_command;
		verbose_tab[3] = &verbose_separator;
		verbose_tab[4] = &verbose_register;
		verbose_tab[5] = &verbose_direct_call;
		verbose_tab[6] = &verbose_comment;
		verbose_tab[7] = &verbose_newline;
		verbose_tab[8] = &verbose_literal_num;
		verbose_tab[9] = &verbose_eof;
		verbose_tab[10] = &verbose_champ_name;
		verbose_tab[11] = &verbose_champ_comment;
		verbose_tab[12] = &verbose_string;
		verbose_tab[13] = &verbose_error;
	}
	return (verbose_tab);
}

static int			verbose_token(t_token *token)
{
	t_verbose	*verb;

	verb = verboser();
	if (verb[token->nature](token) == -1)
		return (-1);
	return (0);
}

static void			padding(int j, char *nature)
{
	if (j < 10)
		ft_printf("\tToken %02d |%s|", j, nature);
	else
		ft_printf("\tToken %d |%s|", j, nature);
}

static int			print_instruction(t_token *node, int verbose)
{
	int			j;
	char		*nature;
	t_token		*ptr;

	j = 0;
	ptr = node;
	while (ptr)
	{
		nature = give_nature(ptr->nature);
		if (verbose == 2)
			padding(j, nature);
		else if (verbose == 1)
			ft_printf("\t\t\t|%s|\n", nature);
		if (verbose == 2)
			if (verbose_token(ptr) == -1)
				return (-1);
		if (!ptr->next_token)
			ft_printf("\n");
		ptr = ptr->next_token;
		ft_strdel(&nature);
		j++;
	}
	return (0);
}

void				print_token_list(t_parser *box)
{
	t_token	*ptr;
	int		i;

	i = 1;
	ptr = box->code;
	if (!box->verbose)
		return ;
	ft_printf("_________________DISPLAYING LEXICAL UNITS________________\n\n");
	while (ptr)
	{
		if (box->verbose > 1)
			ft_printf("\t\t\t--Line %d--\n", i);
		if (print_instruction(ptr, box->verbose) == -1)
		{
			asm_errout(4, box);
			return ;
		}
		ptr = ptr->next_head;
		i++;
	}
	ft_printf("_______________________________________________________\n\n");
	if (box->verbose == 2)
		ft_printf("  ________________DISPLAYING ENCODING________________\n\n");
}
