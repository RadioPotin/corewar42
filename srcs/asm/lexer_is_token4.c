/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_token4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:30:55 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/11 15:35:59 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_string(char *s, int *len)
{
	int i;

	i = 0;
	if (*s == '"')
	{
		i++;
		while (s[i] && s[i] != '"')
			i++;
		if (!s[i])
			return (0);
		*len = i + 1;
		return (1);
	}
	return (0);
}

int		is_champ_name(char *s, int *len)
{
	if (*s == '.')
	{
		if (!ft_strncmp(s, NAME_CMD_STRING, 5))
		{
			*len = 5;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

int		is_champ_comment(char *s, int *len)
{
	if (*s == '.')
	{
		if (!ft_strncmp(s, COMMENT_CMD_STRING, 8))
		{
			*len = 8;
			return (1);
		}
		else
			return (0);
	}
	return (0);
}
