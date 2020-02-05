/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_verbose_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:36:13 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 12:29:25 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		verbose_eof(t_token *token)
{
	(void)token;
	ft_printf("\n");
	return (0);
}

int		verbose_champ_name(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_champ_comment(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}

int		verbose_string(t_token *token)
{
	if (token->location.offset < 10)
		ft_printf(" at col: %d  ( %s )\n", token->location.offset,
				token->content);
	else
		ft_printf(" at col: %d ( %s )\n", token->location.offset,
				token->content);
	return (0);
}
