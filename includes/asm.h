/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:25:26 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/25 12:54:48 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "op_code.h"
# include "error.h"
# include "ft_printf.h"
# define OP_ALPHABET "subtfxorkadzjmnplive"
# define HASHTABLE_SIZE 257
# define ALT_COMMENT_CHAR ';'

typedef enum		e_state
{
	LABEL_DECLARATION,
	LABEL_MENTION,
	OP_CMD,
	SEPARATOR,
	REGISTER,
	DIR_CALL,
	COMMENT,
	NEWLINE,
	LITERAL_NB,
	END,
	CHAMP_NAME,
	CHAMP_COMMENT,
	STRING,
	ERROR,
	START
}					t_state;

typedef enum		e_op
{
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF,
	ERR,
	MALERROR
}					t_op_e;

typedef struct		s_pos
{
	int line;
	int offset;
}					t_pos;

typedef struct		s_head
{
	int				name;
	int				com;
}					t_head;

typedef struct		s_token
{
	t_state			nature;
	t_op_e			op_code;
	t_pos			location;
	char			*content;
	int32_t			size;
	int32_t			relative_addr;
	struct s_token	*next_token;
	struct s_token	*next_head;
}					t_token;

typedef struct		s_label_hash
{
	t_token					*instr_ptr;
	char					*label_name;
	struct s_label_hash		*next_col;
}					t_hash;

typedef struct		s_parser
{
	t_token		*code;
	t_token		*champ_name;
	t_token		*champ_comment;
	t_hash		*labels;
	char		*file;
	int			*bytes_to_write;
	int			arg_index;
	int			fd;
	int			err;
	int			err2;
	int			verbose;
	t_pos		curr_pos;
	int32_t		file_size;
	int32_t		code_size;
}					t_parser;

typedef char		*(*t_encoder)(t_parser *, t_token *arg, int32_t size);
typedef t_token		*(*t_allocator)(t_parser *, int *, int *);
typedef int			(*t_tokenizer)(char *, int *);
typedef int			(*t_verbose)(t_token *);

int					check_arguments(int argc, char **argv, int *v, char **f_n);
int					assembler(char *file, int verbose);
int					asm_errout(int fg, t_parser *box);

int					extract_byte(t_parser *bx, int *byte, char **s, int range);
int					string_to_bytefield(char **dest, char *src, size_t bytes);
int					byte_executable_code_encoder(t_parser *box, int **code);
int					byte_header_encoder(t_parser *box, char **hdr);
int					byte_encoder(t_parser *box, char *filename);
char				*generate_arg(t_parser *box, t_token *op);
char				*generate_op(t_parser *box, t_token *op);
int					convert_nb_to_hex(char *nb, char **hex);
int					convert_dirneg_to_hex(char *nb, char **hex);
int					ft_byte_base(int *str, char *base);
int					init_bytes_to_write(t_parser **box);

t_encoder			*arg_encoder_init(void);
int					dispatch_encoder(t_token *arg, int32_t size);
char				*encode_register(t_parser *bo, t_token *arg, int32_t size);
char				*encode_direct_call(t_parser *b, t_token *arg, int32_t si);
char				*encode_dir_call_neg(t_parser *b, t_token *arg, int32_t si);
char				*encode_label_mention(t_parser *b, t_token *ar, int32_t s);
char				*encode_literal_number(t_parser *b, t_token *a, int32_t s);

int					lexer(t_parser *box);
int					is_end(char *s, int *len);
int					is_string(char *s, int *len);
int					is_newline(char *s, int *len);
int					is_comment(char *s, int *len);
int					is_register(char *s, int *len);
int					is_separator(char *s, int *len);
int					is_champ_name(char *s, int *len);
int					is_literal_nb(char *s, int *len);
int					is_op_command(char *s, int *len);
int					is_direct_call(char *s, int *len);
int					is_indirect_call(char *s, int *len);
int					is_champ_comment(char *s, int *len);
int					is_label_mention(char *s, int *len);
int					is_alphabet_char(char c, char *alpha);
int					is_label_declaration(char *s, int *len);

char				*give_nature(int e);
char				*give_op(int e);

void				free_fields(char **s1, char **s2, char **s3, char **s4);
void				init_fields(char **s1, char **s2, char **s3, char **s4);
void				free_fields_exe(int **tmp, int **code);
int					free_all(t_parser *parse);
void				free_token(t_token *ptr);

int					hash_label_declaration(t_parser *box, t_token *ptr);
int					rot_hash(char *label);

void				print_token_list(t_parser *box);
void				display_lexical_units(void);
void				print_hash(t_parser *box);
void				usage(void);

t_verbose			*verbose(void);
void				verbose_new_instr(t_parser *b, t_token *op, t_token *head);
void				verbose_instr_fields(char *op, char *arg, int *cv, int si);
void				verbose_argfield(t_parser *box, t_token *arg, char *bytef);
int					verbose_label_declaration(t_token *token);
int					verbose_label_mention(t_token *token);
int					verbose_champ_comment(t_token *token);
int					verbose_direct_call(t_token *token);
int					verbose_literal_num(t_token *token);
int					verbose_op_command(t_token *token);
int					verbose_champ_name(t_token *token);
int					verbose_separator(t_token *token);
int					verbose_register(t_token *token);
int					verbose_comment(t_token *token);
int					verbose_newline(t_token *token);
int					verbose_string(t_token *token);
int					verbose_error(t_token *token);
int					verbose_eof(t_token *token);

int					token_storer(t_parser *b, t_state nat, int *i, int *c_len);
t_token				*set_champ_name(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_op_command(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_literal_nb(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_direct_call(t_parser *box, int *curr_i, int *cur_len);
t_token				*set_champ_comment(t_parser *box, int *curr_i, int *c_len);
t_token				*set_label_mention(t_parser *box, int *curr_i, int *c_len);
t_token				*set_label_declaration(t_parser *box, int *cu_i, int *c_l);
t_token				*set_separator(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_register(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_comment(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_newline(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_string(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_error(t_parser *box, int *curr_i, int *curr_len);
t_token				*set_end(t_parser *box, int *curr_i, int *curr_len);

t_token				*error_code_null(t_token *ptr, t_parser *p);
t_token				*is_dir_call(t_token *ptr, t_parser *p);
t_token				*is_ind_call(t_token *ptr, t_parser *p);
t_token				*dispatch(t_token *ptr, t_parser *p);
t_token				*check_header(t_parser *p);
t_token				*skip_coms(t_token *ptr);
t_token				*is_reg(t_token *ptr);
t_token				*is_sep(t_token *ptr);

int					error_header(t_token *ptr, t_parser *p);
int					error_code(t_token *ptr, t_parser *p);

int					is_newline2(t_token *ptr);
int					is_correct(t_parser *p);
int					is_com(t_token *ptr);

int					start_live_zjmp_fork_lfork(t_token *ptr, t_parser *p);
int					start_and_or_xor(t_token *ptr, t_parser *p);
int					start_ldi_lldi(t_token *ptr, t_parser *p);
int					start_add_sub(t_token *ptr, t_parser *p);
int					start_ld_lld(t_token *ptr, t_parser *p);
int					start_aff(t_token *ptr, t_parser *p);
int					start_sti(t_token *ptr, t_parser *p);
int					start_st(t_token *ptr, t_parser *p);

void				get_relative(t_token *p, t_token *save, t_parser *point);
char				*get_real_name(char *str);
int					get_index(t_token *ptr);
int					get_args(t_token *p);
int					count_positive_next(t_token *label_d, int count);
int					count_negative_next(t_token *p, int count);

int					check_label_mention(t_token *ptr, t_parser *p);
void				count(t_token *p, t_parser *point);
int					add_count(t_token *ptr);
void				check_t_dir_size(t_token *ptr);
#endif
