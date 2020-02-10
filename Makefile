# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapinto <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 14:45:04 by dapinto           #+#    #+#              #
#    Updated: 2020/02/10 15:18:31 by dapinto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Printing-#
#No Color
NO_COLOR    = \033[m
#Black
BLACK       = \033[0;30m
#Red
ERROR_COLOR = \033[0;31m
#Green
OK_COLOR    = \033[0;32m
#Yellow
WARN_COLOR  = \033[0;33m
#Blue
BLUE        = \033[0;34m
#Purple
COM_COLOR   = \033[0;35m
#Cyan
OBJ_COLOR   = \033[0;36m
#White
WHITE       = \033[0;37m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else\
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	$(RM) $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[DONE]"
ERROR_STRING = "[OHSHIT]"
WARN_STRING  = "[HOLDUP]"
COM_STRING   = "[PROJECT]"
#-Make-#
ASM_NAME = asm
COREWAR_NAME = corewar
ASM_NAMEDEB = asmdeb
COREWAR_NAMEDEB = corewardeb
CC = clang
WFG = -Wall -Wextra -Werror -g -fsanitize=address
COMP = $(CC) -c
DEBUG = $(CC) -g
ANALYZE = $(DEBUG) -analyze
MKDIR = mkdir -p
DSYM = *.dSYM
MKE = make -C
RMRF = rm -rf
#-Libraries, includes, and paths-#
#-Directories-#
DEBUG_DIR = ./debug/
HEADER_DIR = ./includes/
LIB_INCS += -Ilibft/includes
vpath %.c $(COREWAR_SRCS_DIR)
vpath %.c $(ASM_SRCS_DIR)
vpath %.o $(OBJS_DIR)
vpath %deb.o $(DEBOBJS_DIR)
vpath %.h ./includes/
# ASM
ASM_HDS += asm.h
ASM_HDS += op.h
ASM_HDS += error.h
ASM_HDS += op_code.h
ASM_HEADERS = $(addprefix $(HEADER_DIR), $(ASM_HDS))
ASM_INCS += -I$(HEADER_DIR)
ASM_INCS += $(LIB_INCS)
# COREWAR
COREWAR_HDS += corewar.h
COREWAR_HDS += error.h
COREWAR_HDS += op.h
COREWAR_HEADERS = $(addprefix $(HEADER_DIR), $(COREWAR_HDS))
COREWAR_INCS += -I$(HEADER_DIR)
COREWAR_INCS += $(LIB_INCS)
# LIBFT
LIB_PATH = libft/
MAKE_PATH = libft/
LIB = $(LIB_PATH)libft.a
LIBDEB= $(LIB_PATH)libftdeb.a
#-Sources and paths-#
# ASM
ASM_SRCS = asm.c
ASM_SRCS += assembler.c
ASM_SRCS += asm_errout.c
ASM_SRCS += check_arguments.c
ASM_SRCS += byte_encoder.c
ASM_SRCS += byte_header_encoder.c
ASM_SRCS += byte_execode_encoder.c
ASM_SRCS += byte_encoder_opfield.c
ASM_SRCS += byte_encoder_argfield.c
ASM_SRCS += byte_encoder_argument.c
ASM_SRCS += byte_encoder_converter.c
ASM_SRCS += byte_encoder_converter2.c
ASM_SRCS += free_all.c
ASM_SRCS += label_hashtable.c
ASM_SRCS += lexer.c
ASM_SRCS += lexer_is_token1.c
ASM_SRCS += lexer_is_token2.c
ASM_SRCS += lexer_is_token3.c
ASM_SRCS += lexer_is_token4.c
ASM_SRCS += lexer_token_storer.c
ASM_SRCS += lexer_token_set1.c
ASM_SRCS += lexer_token_set2.c
ASM_SRCS += lexer_token_set3.c
ASM_SRCS += miscellaneous.c
ASM_SRCS += miscellaneous2.c
ASM_SRCS += op_code_init.c
ASM_SRCS += op_code_set_1.c
ASM_SRCS += op_code_set_2.c
ASM_SRCS += op_code_set_3.c
ASM_SRCS += print_hash.c
ASM_SRCS += print_token_list.c
ASM_SRCS += print_verbose_1.c
ASM_SRCS += print_verbose_2.c
ASM_SRCS += print_verbose_3.c
ASM_SRCS += print_verbose_encoder.c
ASM_SRCS += check_header.c
ASM_SRCS += check_label_mention.c
ASM_SRCS += count.c
ASM_SRCS += dispatch.c
ASM_SRCS += error.c
ASM_SRCS += get_index.c
ASM_SRCS += get_relative.c
ASM_SRCS += get_t_dir_size.c
ASM_SRCS += is_com.c
ASM_SRCS += is_reg.c
ASM_SRCS += start_1.c
ASM_SRCS += start_2.c
ASM_SRCS += start_3.c
ASM_SRCS += get_args.c
ASM_SRCS += get_relative_next.c

ASM_SRCS_DIR = ./srcs/asm/
ASM_PATHS = $(addprefix $(ASM_SRCS_DIR), $(ASM_SRCS))
# COREWAR
COREWAR_SRCS = corewar.c
COREWAR_SRCS += read_players.c
COREWAR_SRCS += get_champ.c
COREWAR_SRCS += check_binairy.c
COREWAR_SRCS += place_champs.c
COREWAR_SRCS += resources_fct.c
COREWAR_SRCS += fct_live.c
COREWAR_SRCS += fct_ld.c
COREWAR_SRCS += fct_st.c
COREWAR_SRCS += fct_add.c
COREWAR_SRCS += fct_sub.c
COREWAR_SRCS += fct_and.c
COREWAR_SRCS += fct_or.c
COREWAR_SRCS += fct_xor.c
COREWAR_SRCS += fct_zjmp.c
COREWAR_SRCS += fct_ldi.c
COREWAR_SRCS += fct_sti.c
COREWAR_SRCS += fct_fork.c
COREWAR_SRCS += fct_lld.c
COREWAR_SRCS += fct_lldi.c
COREWAR_SRCS += fct_lfork.c
COREWAR_SRCS += fct_aff.c
COREWAR_SRCS += init_keys.c
COREWAR_SRCS += game.c
COREWAR_SRCS += conclude.c
COREWAR_SRCS += introduce.c
COREWAR_SRCS += arena_fct.c
COREWAR_SRCS += processus.c
COREWAR_SRCS += free_corewar.c
COREWAR_SRCS += hexdump.c
COREWAR_SRCS += death_sentence.c

COREWAR_SRCS_DIR = ./srcs/corewar/
COREWAR_PATHS = $(addprefix $(COREWAR_SRCS_DIR), $(COREWAR_SRCS))
#-Objects-#
OBJS_DIR = ./objects/
DEBOBJS_DIR = ./debug/deb_objects/
# ASM
ASM_OBJS_DIR = ./objects/asm/
ASM_OBJS = $(patsubst %.c, %.o, $(ASM_SRCS))
ASM_OBJS_PATH = $(addprefix $(ASM_OBJS_DIR), $(ASM_OBJS))
# COREWAR
COREWAR_OBJS_DIR = ./objects/corewar/
COREWAR_OBJS = $(patsubst %.c, %.o, $(COREWAR_SRCS))
COREWAR_OBJS_PATH = $(addprefix $(COREWAR_OBJS_DIR), $(COREWAR_OBJS))
# ASM_DEBUG
ASM_DEBOBJS_DIR = $(DEBOBJS_DIR)
ASM_DEBOBJS = $(patsubst %.c, %deb.o, $(ASM_SRCS))
ASM_DEBOBJS_PATH = $(addprefix $(ASM_DEBOBJS_DIR), $(ASM_DEBOBJS))
# COREWAR_DEBUG
COREWAR_DEBOBJS_DIR = $(DEBOBJS_DIR)
COREWAR_DEBOBJS = $(patsubst %.c, %deb.o, $(COREWAR_SRCS))
COREWAR_DEBOBJS_PATH = $(addprefix $(COREWAR_DEBOBJS_DIR), $(COREWAR_DEBOBJS))
#-Rules-#
all: $(ASM_NAME) $(COREWAR_NAME)

debug: $(ASM_NAMEDEB) $(COREWAR_NAMEDEB)

analyze:
	@mkdir -p $(DEBUG_DIR)
	@printf "\e[32m----------\nLaunching analyzer script.\e[39m\n"
	@sh build/analyze.sh

$(LIB): FORCE
	@$(MKE) $(MAKE_PATH)

$(LIBDEB): FORCE
	@$(MKE) $(MAKE_PATH) debug

#ASM && COREWAR
$(ASM_NAME): $(LIB) $(ASM_OBJS_DIR) $(ASM_OBJS_PATH)
	@$(CC) $(WFG) $(ASM_INCS) $(ASM_OBJS_PATH) $(LIB) -o $(ASM_NAME)

$(ASM_OBJS_DIR)%.o : $(ASM_SRCS_DIR)%.c $(ASM_HDS)
	@$(call run_and_test, $(COMP) $(WFG) $(ASM_INCS) $< -o $@)

$(COREWAR_NAME): $(LIB) $(COREWAR_OBJS_DIR) $(COREWAR_OBJS_PATH)
	@$(CC) $(WFG) $(COREWAR_INCS) $(COREWAR_OBJS_PATH) $(LIB) -o $(COREWAR_NAME)

$(COREWAR_OBJS_DIR)%.o : $(COREWAR_SRCS_DIR)%.c $(COREWAR_HDS)
	@$(call run_and_test, $(COMP) $(WFG) $(COREWAR_INCS) $< -o $@)

#DEBUG ASM && DEBUG COREWAR
$(ASM_NAMEDEB): $(LIBDEB) $(ASM_DEBOBJS_DIR) $(ASM_DEBOBJS_PATH)
	@$(DEBUG) $(WFG) $(ASM_INCS) $(ASM_DEBOBJS_PATH) $(LIBDEB) -o $(ASM_NAMEDEB)

$(ASM_DEBOBJS_DIR)%deb.o : $(ASM_SRCS_DIR)%.c $(ASM_HDS)
	@$(call run_and_test, $(DEBUG) -c $(WFG) $(ASM_INCS) $< -o $@)

$(COREWAR_NAMEDEB): $(LIBDEB) $(COREWAR_DEBOBJS_DIR) $(COREWAR_DEBOBJS_PATH)
	@$(DEBUG) $(WFG) $(COREWAR_INCS) $(COREWAR_DEBOBJS_PATH) $(LIBDEB) -o $(COREWAR_NAMEDEB)

$(COREWAR_DEBOBJS_DIR)%deb.o : $(COREWAR_SRCS_DIR)%.c $(COREWAR_HDS)
	@$(call run_and_test, $(DEBUG) -c $(WFG) $(COREWAR_INCS) $< -o $@)

#mkdir
$(DEBOBJS_DIR):
	@mkdir -p $(DEBOBJS_DIR)

$(DEBUG_DIR):
	@mkdir -p $(DEBUG_DIR)

$(ASM_OBJS_DIR):
	@mkdir -p $(ASM_OBJS_DIR)

$(COREWAR_OBJS_DIR):
	@mkdir -p $(COREWAR_OBJS_DIR)

FORCE:

clean:
	@$(MKE) $(MAKE_PATH) clean
	@$(RMRF) $(OBJS_DIR)
	@$(RMRF) $(DEBOBJS_DIR)
	@$(RMRF) $(DEBUG_DIR)static_analyzer
	@$(RMRF) $(DSYM)

fclean: clean
	@$(MKE) $(MAKE_PATH) fclean
	@$(RMRF) $(COREWAR_NAME)
	@$(RMRF) $(COREWAR_NAMEDEB)
	@$(RMRF) $(ASM_NAME)
	@$(RMRF) $(ASM_NAMEDEB)
	@$(RMRF) $(OBJS_DIR)
	@$(RMRF) $(DEBUG_DIR)

re: fclean all

.PHONY: clean fclean re debug all FORCE
