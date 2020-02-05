/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code_set_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:19:05 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:35:17 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	set_and(void)
{
	t_op and;

	and.name = "and";
	and.code = 0x06;
	and.args_num = 3;
	and.args_types_code = true;
	and.args_types[0] = (T_REG | T_DIR | T_IND);
	and.args_types[1] = (T_REG | T_DIR | T_IND);
	and.args_types[2] = T_REG;
	and.t_dir_size = 4;
	return (and);
}

t_op	set_or(void)
{
	t_op or;

	or.name = "or";
	or.code = 0x07;
	or.args_num = 3;
	or.args_types_code = true;
	or.args_types[0] = (T_REG | T_DIR | T_IND);
	or.args_types[1] = (T_REG | T_DIR | T_IND);
	or.args_types[2] = T_REG;
	or.t_dir_size = 4;
	return (or);
}

t_op	set_xor(void)
{
	t_op xor;

	xor.name = "xor";
	xor.code = 0x08;
	xor.args_num = 3;
	xor.args_types_code = true;
	xor.args_types[0] = (T_REG | T_DIR | T_IND);
	xor.args_types[1] = (T_REG | T_DIR | T_IND);
	xor.args_types[2] = T_REG;
	xor.t_dir_size = 4;
	return (xor);
}

t_op	set_zjmp(void)
{
	t_op zjmp;

	zjmp.name = "zjmp";
	zjmp.code = 0x09;
	zjmp.args_num = 1;
	zjmp.args_types_code = false;
	zjmp.args_types[0] = T_DIR;
	zjmp.args_types[1] = 0;
	zjmp.args_types[2] = 0;
	zjmp.t_dir_size = 2;
	return (zjmp);
}

t_op	set_ldi(void)
{
	t_op ldi;

	ldi.name = "ldi";
	ldi.code = 0x0A;
	ldi.args_num = 3;
	ldi.args_types_code = true;
	ldi.args_types[0] = (T_REG | T_DIR | T_IND);
	ldi.args_types[1] = (T_REG | T_DIR);
	ldi.args_types[2] = T_REG;
	ldi.t_dir_size = 2;
	return (ldi);
}
