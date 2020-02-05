/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:22:53 by dapinto           #+#    #+#             */
/*   Updated: 2019/12/12 15:34:31 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int argc, char **argv)
{
	int		verbose;
	int		ret;
	char	*filename;

	verbose = 0;
	if ((ret = check_arguments(argc, argv, &verbose, &filename)) > 0)
		assembler(filename, verbose);
	else
		(ret == 0) ? usage() : display_lexical_units();
	return (0);
}
