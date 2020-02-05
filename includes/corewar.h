/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:57:34 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/16 15:23:56 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "op.h"
# include <errno.h>

# define LIVE_KEY 1
# define LD_KEY 2
# define ST_KEY 3
# define ADD_KEY 4
# define SUB_KEY 5
# define AND_KEY 6
# define OR_KEY 7
# define XOR_KEY 8
# define ZJMP_KEY 9
# define LDI_KEY 10
# define STI_KEY 11
# define FORK_KEY 12
# define LLD_KEY 13
# define LLDI_KEY 14
# define LFORK_KEY 15
# define AFF_KEY 16

typedef struct	s_proc
{
	int				pc;
	int				live;
	int				carry;
	int				waiting;
	int				ready;
	int				regs[REG_NUMBER];
	unsigned int	key;
	struct s_play	*player;
	struct s_proc	*prev;
	struct s_proc	*next;
}				t_proc;

typedef struct	s_play
{
	int				i;
	int				number;
	int				last_live;
	char			name[129];
	char			comment[2049];
	char			*champ;
	unsigned int	c_size;
	unsigned int	size;
}				t_play;

typedef struct	s_cw
{
	int					tmp_nb_p;
	int					error;
	int					players;
	int					cycles;
	int					to_die;
	int					deltas;
	int					nb_lives;
	int					last_delta;
	int					dump;
	int					cl;
	int					no_live;
	int					cp;
	int					times[16];
	unsigned char		arena[4096];
	int					p_color[4096];
	t_proc				*procs;
	t_play				player[4];
}				t_cw;

typedef	int		(*t_pfct)(t_cw *cw, t_proc *prc);

int				read_players(t_cw *cw, int ac, char **av);
int				get_champ(t_cw *cw, char **av, int ac, int i);
int				place_champs(t_cw *cw);
void			init_p_key(t_pfct *pft);
void			init_times_key(int *times);
int				check_binairy(t_cw *cw, char *str);
int				ft_hexdump(t_cw *cw);
int				create_process(t_cw *cw, t_play *pl);
int				loop_game(t_cw *cw);
int				conclude_game(t_cw *cw);
int				introduce(t_cw *cw);
int				absolute_arena(int value);
void			free_corewar(t_cw *cw);
int				absolute_arena(int value);
int				increment_pc(t_proc *prc, unsigned char *types, int use,
				int err);
void			set_key(t_cw *cw, t_proc *prc);
void			death_sentence(t_cw *cw, t_proc *prc);

/*
**	key fonctions
*/

int				live_fct(t_cw *cw, t_proc *prc);
int				ld_fct(t_cw *cw, t_proc *prc);
int				st_fct(t_cw *cw, t_proc *prc);
int				add_fct(t_cw *cw, t_proc *prc);
int				sub_fct(t_cw *cw, t_proc *prc);
int				and_fct(t_cw *cw, t_proc *prc);
int				or_fct(t_cw *cw, t_proc *prc);
int				xor_fct(t_cw *cw, t_proc *prc);
int				zjmp_fct(t_cw *cw, t_proc *prc);
int				ldi_fct(t_cw *cw, t_proc *prc);
int				sti_fct(t_cw *cw, t_proc *prc);
int				fork_fct(t_cw *cw, t_proc *prc);
int				lld_fct(t_cw *cw, t_proc *prc);
int				lldi_fct(t_cw *cw, t_proc *prc);
int				lfork_fct(t_cw *cw, t_proc *prc);
int				aff_fct(t_cw *cw, t_proc *prc);
int				get_size(unsigned char c, int use);
int				get_arg(t_cw *cw, t_proc *prc, unsigned char *str);
int				get_hexa(unsigned char *str, int pc, int lenght);
int				print_in_arena(t_cw *cw, t_proc *prc, int src, int dst);

#endif
