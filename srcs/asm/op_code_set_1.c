/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code_set_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:18:43 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:35:41 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_op	set_live(void)
{
	t_op live;

	live.name = "live";
	live.code = 0x01;
	live.args_num = 1;
	live.args_types_code = false;
	live.args_types[0] = T_DIR;
	live.args_types[1] = 0;
	live.args_types[2] = 0;
	live.t_dir_size = 4;
	return (live);
}

t_op	set_ld(void)
{
	t_op ld;

	ld.name = "ld";
	ld.code = 0x02;
	ld.args_num = 2;
	ld.args_types_code = true;
	ld.args_types[0] = (T_DIR | T_IND);
	ld.args_types[1] = T_REG;
	ld.args_types[2] = 0;
	ld.t_dir_size = 4;
	return (ld);
}

t_op	set_st(void)
{
	t_op st;

	st.name = "st";
	st.code = 0x03;
	st.args_num = 2;
	st.args_types_code = true;
	st.args_types[0] = T_REG;
	st.args_types[1] = (T_REG | T_IND);
	st.args_types[2] = 0;
	st.t_dir_size = 4;
	return (st);
}

t_op	set_add(void)
{
	t_op add;

	add.name = "add";
	add.code = 0x04;
	add.args_num = 3;
	add.args_types_code = true;
	add.args_types[0] = T_REG;
	add.args_types[1] = T_REG;
	add.args_types[2] = T_REG;
	add.t_dir_size = 4;
	return (add);
}

t_op	set_sub(void)
{
	t_op sub;

	sub.name = "sub";
	sub.code = 0x05;
	sub.args_num = 3;
	sub.args_types_code = true;
	sub.args_types[0] = T_REG;
	sub.args_types[1] = T_REG;
	sub.args_types[2] = T_REG;
	sub.t_dir_size = 4;
	return (sub);
}
