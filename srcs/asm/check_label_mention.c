/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label_mention.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:18:08 by casautou          #+#    #+#             */
/*   Updated: 2020/01/25 12:42:55 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_real_name(char *str)
{
	char	*real_name;
	int		i;

	i = 1;
	if (!(real_name = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		real_name[i - 1] = str[i];
		i++;
	}
	real_name[i - 1] = ':';
	real_name[i] = '\0';
	return (real_name);
}

int		check_label_mention(t_token *ptr, t_parser *p)
{
	char	*real_name;
	int		i;
	t_hash	*point;

	if (!p->labels || !(real_name = get_real_name(ptr->content)))
		return (0);
	i = rot_hash(real_name);
	point = &p->labels[i];
	if (point == NULL)
	{
		free(real_name);
		return (0);
	}
	while (point->label_name != NULL)
	{
		if (ft_strcmp(point->label_name, real_name) == 0)
		{
			free(real_name);
			return (1);
		}
		else
			point = point->next_col;
	}
	free(real_name);
	return (0);
}
