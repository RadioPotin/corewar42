/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_execode_encoder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:15:01 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:07:17 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static t_state		instruction_cursor(t_token **curr, t_token **curr_head)
{
	t_token *hptr;
	t_token *iptr;

	hptr = *curr_head;
	iptr = *curr;
	while (hptr && hptr->nature != END)
	{
		while (iptr)
		{
			if (iptr->nature == OP_CMD)
			{
				*curr = iptr;
				*curr_head = hptr;
				return (iptr->nature);
			}
			iptr = iptr->next_token;
		}
		hptr = hptr->next_head;
		iptr = hptr;
	}
	if (!hptr)
		return (ERROR);
	return (hptr->nature);
}

static int			append_instruction_to_code(t_parser *box, int **code,
		int *instruction, int size)
{
	static int	i = 0;

	box->err = 14;
	if (!*code)
	{
		if (!(*code = ft_memalloc(sizeof(int) * box->code_size)))
			return (0);
		ft_bzero(&(*code)[0], sizeof(int) * box->code_size);
		ft_memcpy(&(*code)[0], instruction, sizeof(int) * size);
		i = size;
		return (1);
	}
	else
	{
		ft_memcpy(&(*code)[i], instruction, sizeof(int) * size);
		i += size;
	}
	return (1);
}

static int			*joinfields(t_parser *box, char *op_field, char *arg_field,
		int **size)
{
	int		*converted_instr;
	int		byte[16];
	size_t	len;
	size_t	i;

	i = 0;
	converted_instr = NULL;
	len = (ft_strlen(op_field) * 0.5) + ft_str_nb_of_target(arg_field, "|");
	if (!(converted_instr = ft_memalloc(sizeof(int) * len)))
		return (NULL);
	while (i < len)
	{
		ft_bzero(&byte, sizeof(int[16]));
		if (*op_field && extract_byte(box, byte, &op_field, 2))
			converted_instr[i] = ft_byte_base(byte, "0123456789ABCDEF");
		else if (*arg_field && extract_byte(box, byte, &arg_field,
					ft_strichr(arg_field, '|')))
			converted_instr[i] = ft_byte_base(byte, "0123456789ABCDEF");
		i++;
	}
	**size = len;
	return (converted_instr);
}

static int			*feed_instruction_code(t_parser *box, t_token *op,
		int *size)
{
	char	*op_field;
	char	*arg_field;
	int		*field;

	box->err = 14;
	if (!(box->bytes_to_write))
		if (!init_bytes_to_write(&box))
			return (NULL);
	if (!(op_field = generate_op(box, op))
			|| !(arg_field = generate_arg(box, op)))
	{
		ft_strdel(&op_field);
		return (NULL);
	}
	else if (!(field = joinfields(box, op_field, arg_field, &size)))
	{
		ft_strdel(&op_field);
		ft_strdel(&arg_field);
		return (NULL);
	}
	if (box->verbose == 2)
		verbose_instr_fields(op_field, arg_field, field, *size);
	ft_strdel(&op_field);
	ft_strdel(&arg_field);
	return (field);
}

int					byte_executable_code_encoder(t_parser *box, int **code)
{
	t_state		state;
	t_token		*head;
	t_token		*ptr;
	int			*arg_values;
	int			size;

	ptr = box->code;
	head = box->code;
	while ((state = instruction_cursor(&ptr, &head)) != END && state != ERROR)
	{
		verbose_new_instr(box, ptr, head);
		if (!(arg_values = feed_instruction_code(box, ptr, &size)))
		{
			free_fields_exe(&arg_values, code);
			return (asm_errout(box->err, box));
		}
		else if (!append_instruction_to_code(box, code, arg_values, size))
		{
			free_fields_exe(&arg_values, code);
			return (asm_errout(box->err, box));
		}
		ptr = ptr->next_token;
		free(arg_values);
	}
	return (1);
}
