/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_is_token2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:55:14 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 11:11:59 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_alphabet_char(char c, char *alphabet)
{
	int i;

	i = 0;
	while (alphabet[i])
	{
		if (c == alphabet[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_label_declaration(char *s, int *len)
{
	int i;
	int label_end;

	i = 1;
	if (is_alphabet_char(*s, LABEL_CHARS))
	{
		label_end = ft_strichr(s, LABEL_CHAR);
		while (i < label_end)
		{
			if (is_alphabet_char(s[i], LABEL_CHARS))
				i++;
			else
				return (0);
		}
		*len = label_end + 1;
		return (1);
	}
	return (0);
}

int		is_label_mention(char *s, int *len)
{
	int label_end;

	if (*s == LABEL_CHAR)
	{
		label_end = ft_nonchrseti(s + 1, LABEL_CHARS);
		if (label_end == 0)
			return (0);
		else
			*len = label_end;
		return (1);
	}
	return (0);
}

int		is_separator(char *s, int *len)
{
	if (*s == SEPARATOR_CHAR)
	{
		*len = 1;
		return (1);
	}
	return (0);
}
