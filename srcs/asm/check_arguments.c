/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:15:29 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/30 13:15:49 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		assert_file(char *filename, int i, int **arg)
{
	char *ptr;

	if (ft_str_nb_of_target(filename, ".s"))
	{
		ptr = ft_strrchr(filename, '.');
		if (*(ptr + 1) == 's' && !*(ptr + 2))
		{
			**arg = i;
			return (1);
		}
	}
	return (0);
}

static int		look_for_help_and_checkfile(char **arguments, int *arg)
{
	int i;

	i = 1;
	while (arguments[i])
	{
		if ((!ft_strcmp(arguments[i], "--help")
					|| !ft_strcmp(arguments[i], "--h"))
				|| (ft_strstr(arguments[i], ".s")
					&& !assert_file(arguments[i], i, &arg)))
			return (0);
		i++;
	}
	if (!*arg)
		return (0);
	return (1);
}

static int		detect_lexical_unit_exp(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--token-explanation")
				|| !ft_strcmp(argv[i], "--exp"))
			return (1);
		i++;
	}
	return (0);
}

static int		detect_verbose(char **argv, int *verbose)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "--verbose-full")
				|| !ft_strcmp(argv[i], "--vf"))
		{
			*verbose = 2;
			return (1);
		}
		else if (*verbose != 2 && (!ft_strcmp(argv[i], "--verbose")
					|| !ft_strcmp(argv[i], "--v")))
			*verbose = 1;
		i++;
	}
	return (0);
}

int				check_arguments(int argc, char **argv, int *verbose,
		char **file)
{
	int arg;

	arg = 0;
	if (argc == 1 || argc > 10 || !look_for_help_and_checkfile(argv, &arg))
		return (0);
	*file = argv[arg];
	if (detect_lexical_unit_exp(argv))
		return (-1);
	detect_verbose(argv, verbose);
	return (1);
}
