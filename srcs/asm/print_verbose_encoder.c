/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verbose_encoder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:36:42 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/07 17:42:27 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verbose_new_instr(t_parser *box, t_token *ptr, t_token *head_op)
{
	char *op;

	if (box->verbose == 2)
	{
		op = give_op(head_op->op_code);
		ft_printf("NEW INSTRUCTION: Line %d at OP %s.\n\n",
				ptr->location.line, op);
		ft_strdel(&op);
	}
}

void	verbose_instr_fields(char *opfield, char *argfield, int *cov, int size)
{
	int i;

	i = 0;
	if (ft_strlen(opfield) == 2)
		ft_printf("\n\tOP FIELD  +  ARG FIELD\n\t |%s|     +  |%s\n", opfield,
				argfield);
	else
		ft_printf("\n\tOP FIELD  +  ARG FIELD\n\t|%s|    +  |%s\n", opfield,
				argfield);
	ft_printf("\t          == ");
	while (i < size)
		ft_printf("|%x|", cov[i++]);
	ft_printf("\n>-----------------------------------------------------<");
	ft_printf("\n\n");
}

void	verbose_argfield(t_parser *box, t_token *arg, char *byte_field)
{
	char *nature;

	if (box->verbose == 2)
	{
		nature = give_nature(arg->nature);
		if (arg->nature == DIR_CALL)
		{
			ft_printf("\t--> CONVERTING %s\n", nature);
			verbose_argfield(box, arg->next_token, byte_field);
			ft_strdel(&nature);
			return ;
		}
		else if (arg->nature == LABEL_MENTION)
			ft_printf("\t--> CONVERTING %s, declaration rel.addr = %d\n",
					nature, arg->relative_addr);
		else if (arg->nature == REGISTER)
			ft_printf("\t--> CONVERTING %s\n", nature);
		ft_printf("\t\tConversion of argument %s gives field |%s\n", nature,
				byte_field);
		ft_strdel(&nature);
	}
}
