/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code_set_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:32 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:35:31 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	set_sti(void)
{
	t_op sti;

	sti.name = "sti";
	sti.code = 0x0B;
	sti.args_num = 3;
	sti.args_types_code = true;
	sti.args_types[0] = T_REG;
	sti.args_types[1] = (T_REG | T_DIR | T_IND);
	sti.args_types[2] = (T_REG | T_DIR);
	sti.t_dir_size = 2;
	return (sti);
}

t_op	set_fork(void)
{
	t_op fork;

	fork.name = "fork";
	fork.code = 0x0C;
	fork.args_num = 1;
	fork.args_types_code = false;
	fork.args_types[0] = T_DIR;
	fork.args_types[1] = 0;
	fork.args_types[2] = 0;
	fork.t_dir_size = 2;
	return (fork);
}

t_op	set_lld(void)
{
	t_op lld;

	lld.name = "lld";
	lld.code = 0x0D;
	lld.args_num = 2;
	lld.args_types_code = true;
	lld.args_types[0] = (T_DIR | T_IND);
	lld.args_types[1] = T_REG;
	lld.args_types[2] = 0;
	lld.t_dir_size = 4;
	return (lld);
}

t_op	set_lldi(void)
{
	t_op lldi;

	lldi.name = "lldi";
	lldi.code = 0x0E;
	lldi.args_num = 3;
	lldi.args_types_code = true;
	lldi.args_types[0] = (T_REG | T_DIR | T_IND);
	lldi.args_types[1] = (T_REG | T_DIR);
	lldi.args_types[2] = T_REG;
	lldi.t_dir_size = 2;
	return (lldi);
}

t_op	set_lfork(void)
{
	t_op lfork;

	lfork.name = "lfork";
	lfork.code = 0x0F;
	lfork.args_num = 1;
	lfork.args_types_code = false;
	lfork.args_types[0] = T_DIR;
	lfork.args_types[1] = 0;
	lfork.args_types[2] = 0;
	lfork.t_dir_size = 2;
	return (lfork);
}
