/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:17:54 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 12:07:34 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		is_champ_com(t_token *ptr)
{
	if (!(ptr && ptr->nature == CHAMP_COMMENT))
		return (0);
	if (!(ptr->next_token && ptr->next_token->nature == STRING))
		return (0);
	ptr = ptr->next_token->next_token;
	if (ptr->content == NULL)
		return (1);
	return (is_com(ptr));
}

static int		is_name(t_token *ptr)
{
	if (!(ptr && ptr->nature == CHAMP_NAME))
		return (0);
	if (!(ptr->next_token && ptr->next_token->nature == STRING))
		return (0);
	ptr = ptr->next_token->next_token;
	if (ptr->content == NULL)
		return (1);
	return (is_com(ptr));
}

static t_token	*get_header(t_token *ptr, t_head *h)
{
	if (is_name(ptr))
	{
		if (h->name == 1)
			return (NULL);
		h->name = 1;
		return (ptr->next_head);
	}
	if (is_champ_com(ptr))
	{
		if (h->com == 1)
			return (NULL);
		h->com = 1;
		return (ptr->next_head);
	}
	return (NULL);
}

t_token			*skip_coms(t_token *ptr)
{
	while (is_com(ptr) || is_newline2(ptr))
		ptr = ptr->next_head;
	return (ptr);
}

t_token			*check_header(t_parser *p)
{
	t_token *ptr;
	t_head	h;
	t_token *save;

	h.name = 0;
	h.com = 0;
	save = NULL;
	ptr = p->code;
	while (h.name == 0 || h.com == 0)
	{
		if (ptr == NULL)
		{
			error_header(save, p);
			return (NULL);
		}
		ptr = skip_coms(ptr);
		save = ptr;
		ptr = get_header(ptr, &h);
	}
	ptr = skip_coms(ptr);
	return (ptr);
}
