/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:24:36 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/14 11:34:49 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*give_nature(int nature)
{
	static char		*token_tab[15];

	if (!token_tab[0])
	{
		token_tab[0] = "LABEL_DECL";
		token_tab[1] = "LABEL_MENT";
		token_tab[2] = "OP_COMMAND";
		token_tab[3] = "SEPARATOR_";
		token_tab[4] = "REGISTER_T";
		token_tab[5] = "DIRECT_CAL";
		token_tab[6] = "COMMENT_TK";
		token_tab[7] = "NEWLINE_TK";
		token_tab[8] = "LIT_NUM_TK";
		token_tab[9] = "END_O_FILE";
		token_tab[10] = "CHAMP_NAME";
		token_tab[11] = "CHAMP_COMM";
		token_tab[12] = "STRING_TKN";
		token_tab[13] = "START_TOKN";
		token_tab[14] = "ERROR_TOKN";
	}
	return (ft_strdup(token_tab[nature]));
}

static void		display_op_champ_str_tokens(void)
{
	ft_printf("|OP_COMMAND|: Stands for all operation commands in Corewar.\n");
	ft_printf("\t(live, add, sub, st, sti, ld, lld, ldi, lldi, fork, lfork, ");
	ft_printf("or, xor, and, zjmp, aff)\n\n|CHAMP_NAME| && |CHAMP_COMM|: sta");
	ft_printf("nd for occurances of NAME_CMD_STRING and COMMENT_CMD_STRING c");
	ft_printf("onstant strings.\n\tCurrent: (\"%s\") and ", NAME_CMD_STRING);
	ft_printf("(\"%s\")\n\n|STRING_TKN|: Stand for every", COMMENT_CMD_STRING);
	ft_printf("thing between a pair of ('\"') characters.\n\n");
}

void			display_lexical_units(void)
{
	display_op_champ_str_tokens();
	ft_printf("|LIT_NUM_TK|: Stands for integers found in the source file.\n");
	ft_printf("\tRegex: ([-][0123456789*])\n\n|SEPARATOR_|: Stands for all o");
	ft_printf("ccurances of arg SEPARATOR_CHAR constant character.\n\tCurren");
	ft_printf("t: ('%c')\n\n|REGISTER_T|: Stands for registe", SEPARATOR_CHAR);
	ft_printf("r type arguments.\n\tRegex: ([r] + [one or two digits positiv");
	ft_printf("e LIT_NUM_TK])\n\n|DIRECT_CAL|: Stands for all occurances of ");
	ft_printf("DIRECT_CHAR constant character. (ie. T_DIR argument type).\n");
	ft_printf("\tCurrent: ('%c')\n\n|COMMENT_TK|: Stands for al", DIRECT_CHAR);
	ft_printf("l occurances of COMMENT_CHAR or ALT_COMMENT_CHAR constant cha");
	ft_printf("racters.\n\tCurrent: ('%c' and ", COMMENT_CHAR);
	ft_printf("'%c')\n\tRegex: ([COMMENT_CHAR || ALT_COMME", ALT_COMMENT_CHAR);
	ft_printf("NT_CHAR] + COM + NEWLINE_TK\n\n|LABEL_DECL|: Stands for all l");
	ft_printf("abel declarations.\n\tCurrent LABEL_CHAR: ('%c')", LABEL_CHAR);
	ft_printf("\n\tCurrent LABEL_ALPHA: (\"%s\")\n\tRegex: (LAB", LABEL_CHARS);
	ft_printf("EL_ALPHA + LABEL_CHAR)\n\n|LABEL_MENT|: Stands for all label");
	ft_printf(" mentions.\n\tCurrent LABEL_CHAR: ('%c')\n\tCurre", LABEL_CHAR);
	ft_printf("nt LABEL_ALPHA: (\"%s\")\n\tRegex: (LABEL_CHAR +", LABEL_CHARS);
	ft_printf(" LABEL_ALPHA)\n\n|NEWLINE_TK|: Stands for occura", LABEL_CHARS);
	ft_printf("nces of the '\\n' character.\n\n|END_O_FILE|: Occurs whenever");
	ft_printf(" EoF is found.\n");
}

void			usage(void)
{
	ft_printf("USAGE:\t./asm [Path/To/Filename.s] [--help | --h] [--token-ex");
	ft_printf("planation | --exp] [--verbose-full | --vf || --verbose | --v ");
	ft_printf("]\n\t[asm]:\n\t\tBinary Assembler for Corewar Project.\n\t\tA");
	ft_printf("rguments hierarchy go from top to low: [Filename.s] > [--h] >");
	ft_printf(" [--exp] > [--vf] > [--v].\n\t\t[asm] will only accept from o");
	ft_printf("ne to the total number of available options number of argumen");
	ft_printf("ts.\n\t\tSee below for more info.\n\n\t[Path/To/Filename.s]:");
	ft_printf("\n\t\tFilename must obey <*.s> otherwise usage will be displa");
	ft_printf("yed, its presence is mandatory.\n\nOPTIONS: Options may be pl");
	ft_printf("aced in whichever order. Unknown options will be ignored.\n\t");
	ft_printf("[--help] or [--h]:\n\t\tDisplays usage.\n\n\t[--token-explana");
	ft_printf("tion] or [--exp]:\n\t\tShows meaning of tokens displayed via ");
	ft_printf("verbose options.\n\n\t[--verbose] or [--v]:\n\t\tDisplays nat");
	ft_printf("ure of lexical units in order of appearance in the file.\n\t");
	ft_printf("\tInformation on said lexical units is limited.\n\t\tAlso giv");
	ft_printf("es limited information in case of error.\n\n\t[--verbose-full");
	ft_printf("] or [--vf]:\n\t\tDisplays nature of lexical units in order o");
	ft_printf("f appearance in the file.\n\t\tInformation on said lexical un");
	ft_printf("its is extensive.\n\t\tAlso gives extensive information in ca");
	ft_printf("se of error.\n\t\t[--vf] also displays extensive information");
	ft_printf(" on the encoding of each instruction found in source file.\n");
}
