/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_token1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:52:23 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/15 12:27:36 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_comment(char *s, int *len)
{
	int i;

	i = 1;
	if (*s == COMMENT_CHAR || *s == ALT_COMMENT_CHAR)
	{
		while (s[i] && s[i] != '\n')
			i++;
		if (!s[i])
			return (0);
		*len = i;
		return (1);
	}
	return (0);
}

int		is_direct_call(char *s, int *len)
{
	int i;

	i = 1;
	if (*s == DIRECT_CHAR)
	{
		*len = i;
		return (1);
	}
	return (0);
}

int		is_end(char *s, int *len)
{
	if (!*s)
	{
		*len = 0;
		return (1);
	}
	return (0);
}

int		is_literal_nb(char *s, int *len)
{
	int i;

	i = 1;
	if (ft_isdigit(*s))
	{
		while (ft_isdigit(s[i]))
			i++;
		*len = i;
		return (1);
	}
	else if (*s == '-' && ft_isdigit(s[i]))
	{
		while (ft_isdigit(s[i]))
			i++;
		*len = i;
		return (1);
	}
	return (0);
}

int		is_newline(char *s, int *len)
{
	if (*s == '\n')
	{
		*len = 1;
		return (1);
	}
	return (0);
}
