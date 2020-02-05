/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_code.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:49:04 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:36:54 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_CODE_H
# define OP_CODE_H
# include "op.h"
# include <stdint.h>

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_op
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	t_bool		args_types_code;
	uint8_t		args_types[3];
	uint8_t		t_dir_size;
}				t_op;

t_op			*fetch_op(void);
t_op			set_add(void);
t_op			set_live(void);
t_op			set_sti(void);
t_op			set_ld(void);
t_op			set_ldi(void);
t_op			set_st(void);
t_op			set_sub(void);
t_op			set_aff(void);
t_op			set_lfork(void);
t_op			set_fork(void);
t_op			set_and(void);
t_op			set_or(void);
t_op			set_xor(void);
t_op			set_zjmp(void);
t_op			set_lld(void);
t_op			set_lldi(void);

#endif
