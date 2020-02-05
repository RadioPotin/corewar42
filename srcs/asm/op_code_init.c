/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:33:49 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:35:07 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_fields(char **s1, char **s2, char **s3, char **s4)
{
	*s1 = NULL;
	*s2 = NULL;
	*s3 = NULL;
	*s4 = NULL;
}

t_op	set_aff(void)
{
	t_op aff;

	aff.name = "aff";
	aff.code = 0x10;
	aff.args_num = 1;
	aff.args_types_code = true;
	aff.args_types[0] = T_REG;
	aff.args_types[1] = 0;
	aff.args_types[2] = 0;
	aff.t_dir_size = 4;
	return (aff);
}

t_op	*fetch_op(void)
{
	static t_op op_command_man[16];

	if (!op_command_man[0].name)
	{
		op_command_man[0] = set_live();
		op_command_man[1] = set_ld();
		op_command_man[2] = set_st();
		op_command_man[3] = set_add();
		op_command_man[4] = set_sub();
		op_command_man[5] = set_and();
		op_command_man[6] = set_or();
		op_command_man[7] = set_xor();
		op_command_man[8] = set_zjmp();
		op_command_man[9] = set_ldi();
		op_command_man[10] = set_sti();
		op_command_man[11] = set_fork();
		op_command_man[12] = set_lld();
		op_command_man[13] = set_lldi();
		op_command_man[14] = set_lfork();
		op_command_man[15] = set_aff();
	}
	return (op_command_man);
}
