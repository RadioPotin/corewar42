/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:22:51 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:22:02 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "fcntl.h"

static int		get_file(t_parser *box, char *filename)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (asm_errout(2, box));
	if (!(box->file = get_full_file(fd)))
	{
		close(fd);
		return (asm_errout(3, box));
	}
	close(fd);
	return (0);
}

int				assembler(char *filename, int verbose)
{
	t_parser		parser;

	ft_bzero(&parser, sizeof(t_parser));
	parser.verbose = verbose;
	if (get_file(&parser, filename) == -1)
		return (-1);
	if (lexer(&parser) == -1)
		return (free_all(&parser));
	if (!is_correct(&parser))
		return (free_all(&parser));
	print_token_list(&parser);
	if (byte_encoder(&parser, filename) == -1)
		return (free_all(&parser));
	free_all(&parser);
	return (0);
}
