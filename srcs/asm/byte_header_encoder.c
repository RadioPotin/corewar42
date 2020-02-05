/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_header_encoder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:04:56 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:03:21 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		assert_header_validity(int *err, int32_t name_size,
		int32_t comment_size, int32_t code_size)
{
	*err = 0;
	if (name_size > PROG_NAME_LENGTH)
		*err = 10;
	else if (comment_size > COMMENT_LENGTH)
		*err = 11;
	else if (code_size > CHAMP_MAX_SIZE)
		*err = 12;
	return (0);
}

static int		code_size_conversion(char **code, int32_t size)
{
	int32_t			n;
	unsigned char	bytes[4];

	n = size;
	bytes[0] = (n >> 24) & 0xFF;
	bytes[1] = (n >> 16) & 0xFF;
	bytes[2] = (n >> 8) & 0xFF;
	bytes[3] = n & 0xFF;
	if (!(*code = ft_strnew(sizeof(unsigned char) * 5)))
		return (-1);
	(*code)[4] = '\0';
	ft_memcpy(&(*code)[0], bytes, 4);
	return (0);
}

static int		header_encoder(char **hdr, char *champ_com, char *champ_name,
		char *code_size)
{
	int32_t			n;
	unsigned char	bytes[4];

	n = COREWAR_EXEC_MAGIC;
	bytes[0] = (n >> 24) & 0xFF;
	bytes[1] = (n >> 16) & 0xFF;
	bytes[2] = (n >> 8) & 0xFF;
	bytes[3] = n & 0xFF;
	ft_memcpy(&(*hdr)[0], bytes, 4);
	ft_memcpy(&(*hdr)[4], champ_name, PROG_NAME_LENGTH);
	ft_memcpy(&(*hdr)[132], "\0\0\0\0", 4);
	ft_memcpy(&(*hdr)[136], code_size, 4);
	ft_memcpy(&(*hdr)[140], champ_com, COMMENT_LENGTH);
	ft_memcpy(&(*hdr)[2188], "\0\0\0\0", 4);
	return (0);
}

static char		*headerer(t_parser *box)
{
	char	*champ_name;
	char	*champ_com;
	char	*code_size;
	char	*hdr;

	champ_name = NULL;
	champ_com = NULL;
	code_size = NULL;
	if (!(hdr = ft_strnew(sizeof(char) * 2192)))
		return (NULL);
	if (string_to_bytefield(&champ_name, box->champ_name->next_token->content,
				PROG_NAME_LENGTH) == -1
			|| string_to_bytefield(&champ_com,
				box->champ_comment->next_token->content, COMMENT_LENGTH) == -1
			|| code_size_conversion(&code_size, box->code_size) == -1
			|| header_encoder(&hdr, champ_com, champ_name, code_size) == -1)
	{
		free_fields(&champ_com, &champ_name, &code_size, &hdr);
		return (NULL);
	}
	ft_strdel(&champ_name);
	ft_strdel(&champ_com);
	ft_strdel(&code_size);
	return (hdr);
}

int				byte_header_encoder(t_parser *box, char **hdr)
{
	if (assert_header_validity(&box->err, box->champ_name->next_token->size,
				box->champ_comment->next_token->size, box->code_size) == 0
			&& box->err)
		return (asm_errout(box->err, box));
	if (!(*hdr = headerer(box)))
		return (asm_errout(13, box));
	return (1);
}
