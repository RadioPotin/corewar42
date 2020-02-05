/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_relative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:19:31 by casautou          #+#    #+#             */
/*   Updated: 2020/01/16 10:45:06 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		count_positive(t_token *p, t_token *label_d
, t_token *save, t_token *apply)
{
	int count;
	int l;

	count = 0;
	l = save->location.line;
	p = save;
	save = save->next_head;
	while (l < label_d->location.line)
	{
		count = count_positive_next(p, count);
		p = save;
		save = save->next_head;
		l++;
	}
	apply->relative_addr = count;
}

static void		count_negative(t_token *p, t_token *label_d
, t_token *save, t_token *apply)
{
	int count;
	int l;

	count = 0;
	l = label_d->location.line;
	save = label_d->next_head;
	while (l < p->location.line)
	{
		count = count_negative_next(label_d, count);
		label_d = save;
		save = save->next_head;
		l++;
	}
	apply->relative_addr = -count;
}

t_token			*get_label_declaration(t_token *p, t_parser *point)
{
	char	*str;
	int		i;
	t_hash	*ptr;

	if (!(str = get_real_name(p->content)))
		return (NULL);
	i = rot_hash(str);
	ptr = &point->labels[i];
	if (ptr == NULL)
	{
		free(str);
		return (NULL);
	}
	while (ptr->label_name != NULL)
	{
		if (ft_strcmp(ptr->label_name, str) == 0)
		{
			free(str);
			return (ptr->instr_ptr);
		}
		else
			ptr = ptr->next_col;
	}
	free(str);
	return (ptr->instr_ptr);
}

void			get_relative(t_token *p, t_token *save, t_parser *point)
{
	t_token *label_d;
	t_token *apply;

	apply = p;
	label_d = get_label_declaration(p, point);
	if (label_d->location.line > p->location.line)
		count_positive(p, label_d, save, apply);
	else
		count_negative(p, label_d, save, apply);
}
