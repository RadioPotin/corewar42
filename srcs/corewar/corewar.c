/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjuste <gjuste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:44:42 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 10:09:03 by gjuste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	print_usage(int ret)
{
	ft_printf("usage : ./corewar [-dump *number* -cp -cl -nl] <[-n *number*] ");
	ft_printf("\"champname.cor\"> <...> \n \t -dump *number* dumps memory ");
	ft_printf("after *number* cycles\n \t -cp lets you jump forward cycle by ");
	ft_printf("cycle, or you can jump at a cycle by typing his number of the ");
	ft_printf("standard entry (you can\'t go back, trying to do so will res");
	ft_printf("ult in the game finishing itself)\n \t -cl colors the players ");
	ft_printf("territory and changes color each time a player writes somewher");
	ft_printf("e in the arena\n\t -nl hides lives statements each time a ");
	ft_printf("process declares a player alive (this option is also active ");
	ft_printf("when the cp option is active)\n\n");
	ft_printf("**************************************************************");
	ft_printf("**************************************************************");
	ft_printf("***********************\n\n\t -n lets you choose the number of");
	ft_printf(" your player. By default, players will be asigned numbers from");
	ft_printf(" 1 to 4\n\t\t please note that 4 players maximum can fight ");
	ft_printf("simultaneously, and at least one player is required to play a ");
	ft_printf("game (this player would face himself)\n");
	exit(ret);
}

static void	do_error(t_cw *cw)
{
	if (errno)
		perror("Error");
	else if (cw->error == 0)
		print_usage(-1);
	else if (cw->error == 1)
		ft_printf("ERROR : Empty champion name\n");
	else if (cw->error == 2)
		ft_printf("ERROR : Empty champion comment\n");
	else if (cw->error == 3)
		ft_printf("ERROR : File is not executable\n");
	else if (cw->error == 4)
	{
		ft_printf("ERROR : Size written in the champion is not the same");
		ft_printf(" as the real size\n");
	}
	else if (cw->error == 5)
		ft_printf("ERROR : Header not well formated or too short\n");
	else if (cw->error == 6)
		ft_printf("ERROR : Oops... initialization failed !\n");
	exit(-1);
}

int			main(int ac, char **av)
{
	t_cw	cw;

	ft_bzero(&cw, sizeof(cw));
	init_times_key(cw.times);
	cw.dump = -1;
	if (ac >= 2 && ft_strcmp(av[1], "-h") == 0)
		print_usage(0);
	if (read_players(&cw, ac, av) == -1)
	{
		free_corewar(&cw);
		do_error(&cw);
	}
	introduce(&cw);
	place_champs(&cw);
	if (loop_game(&cw) == 0)
		conclude_game(&cw);
	free_corewar(&cw);
	return (0);
}
