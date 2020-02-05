/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_errout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:13:44 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/15 11:20:58 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "error.h"

static char		*error_selector(int index)
{
	char *msg_tab[19];

	msg_tab[0] = TAB_FILE_NAME_ERROR;
	msg_tab[1] = TAB_TKN_ALLOCATION_ERROR;
	msg_tab[2] = TAB_OPEN_ERROR;
	msg_tab[3] = TAB_FILE_STORAGE_ERROR;
	msg_tab[4] = TAB_PRINTING_ERROR;
	msg_tab[5] = TAB_HASHTABLE_ERROR;
	msg_tab[6] = TAB_TOKEN_GENERATION_ERROR;
	msg_tab[7] = TAB_NAME_MISS;
	msg_tab[8] = TAB_COMMENT_MISS;
	msg_tab[9] = TAB_HDRFIEL;
	msg_tab[10] = TAB_HDRNAME;
	msg_tab[11] = TAB_HDRCOMM;
	msg_tab[12] = TAB_SIZE;
	msg_tab[13] = TAB_HDR_MERROR;
	msg_tab[14] = TAB_EXE_MERROR;
	msg_tab[15] = TAB_ENCOD_FIELD;
	msg_tab[16] = TAB_LITCONV;
	msg_tab[17] = TAB_OPEN_DEST;
	msg_tab[18] = TAB_WRITE_ERR;
	return (msg_tab[index]);
}

static int		verbose_errout(t_parser *box, int err)
{
	if (err == 6 || err == 15)
		ft_printf("Token location: line: %d, column: %d.\n",
				box->curr_pos.line, box->curr_pos.offset);
	return (0);
}

int				asm_errout(int err, t_parser *box)
{
	if (box->verbose)
	{
		ft_printf("%s\n", error_selector(err));
		if (box->verbose == 2)
			verbose_errout(box, err);
	}
	else
		ft_printf("ERROR.\n");
	return (-1);
}
