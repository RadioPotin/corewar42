/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verbose_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:33:54 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 12:27:41 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		verbose_label_declaration(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_label_mention(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_direct_call(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_literal_num(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_op_command(t_token *token)
{
	char		*op_cmd;

	if (!(op_cmd = give_op(token->op_code)))
		return (-1);
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	ft_strdel(&op_cmd);
	return (0);
}
