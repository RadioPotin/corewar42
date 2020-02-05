/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_encoder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:19:41 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:37:52 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>
#include <unistd.h>

static int		open_destination_file(t_parser *box, char *filename)
{
	int		fd;
	int		i;
	char	*dest;
	char	*file;

	i = 0;
	dest = ft_strrchr(filename, '.');
	while (&filename[i] != dest)
		i++;
	if (!(dest = ft_strsub(filename, 0, i))
			|| !(file = ft_strjoin(dest, ".cor")))
	{
		ft_strdel(&dest);
		box->err = 17;
		return (-1);
	}
	ft_strdel(&dest);
	if ((fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
	{
		box->err = 17;
		ft_strdel(&file);
		return (-1);
	}
	ft_strdel(&file);
	return (fd);
}

static int		write_champ(t_parser *box, int fd, char *header, int *code)
{
	int		i;
	char	c;

	box->arg_index = 0;
	if (write(fd, header, 2192) <= 0)
		return (asm_errout(18, box));
	ft_printf("Writing to destination file.\n");
	while ((i = box->bytes_to_write[box->arg_index]))
	{
		while (i > 0)
		{
			c = ((char *)(&(code[box->arg_index])))[i - 1];
			if (write(fd, &c, 1) <= 0)
				return (asm_errout(18, box));
			i--;
		}
		box->arg_index++;
	}
	return (1);
}

int				byte_encoder(t_parser *box, char *filename)
{
	char	*header;
	int		*code;
	int		fd;

	header = NULL;
	code = NULL;
	if (byte_header_encoder(box, &header) == -1
		|| byte_executable_code_encoder(box, &code) == -1)
		return (-1);
	if ((fd = open_destination_file(box, filename)) == -1
			|| write_champ(box, fd, header, code) == -1)
	{
		ft_strdel(&header);
		if (code)
			free(code);
		return (-1);
	}
	ft_strdel(&header);
	if (code)
		free(code);
	return (0);
}
