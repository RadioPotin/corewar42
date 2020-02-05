/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:11:48 by dapinto           #+#    #+#             */
/*   Updated: 2019/01/02 11:39:42 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096
# define OPN_MX 4896
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int					get_next_line(const int fd, char **line);

#endif
