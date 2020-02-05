/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verbose_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:35:02 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 12:30:28 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			verbose_separator(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int			verbose_register(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int			verbose_comment(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int			verbose_newline(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d\n", token->location.offset);
	else
		ft_printf(" at col: %d\n", token->location.offset);
	return (0);
}

int			verbose_error(t_token *token)
{
	ft_printf(" at col: %d ( %s )\n", token->location.offset, token->content);
	return (0);
}
