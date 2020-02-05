/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_com.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casautou <casautou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:20:07 by casautou          #+#    #+#             */
/*   Updated: 2020/01/17 10:17:53 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		is_com(t_token *ptr)
{
	if (!(ptr))
		return (0);
	if (!(ptr->nature == COMMENT))
		return (0);
	if (!(ptr->next_token))
		return (0);
	if (!(ptr->next_token->nature == NEWLINE))
		return (0);
	if (ptr->next_token->next_token)
		return (0);
	return (1);
}

int		is_correct(t_parser *p)
{
	t_token *ptr;
	t_token *save;

	ptr = NULL;
	if (!(ptr = check_header(p)))
		return (0);
	save = skip_coms(ptr);
	if (ptr->nature == END)
		return (error_code(ptr, p));
	while (ptr)
	{
		ptr = skip_coms(ptr);
		if (ptr->nature == END)
			break ;
		if (!(ptr = dispatch(ptr, p)))
			return (0);
	}
	check_t_dir_size(save);
	count(save, p);
	return (1);
}

t_token	*is_dir_call(t_token *ptr, t_parser *p)
{
	if (!(ptr))
		return (NULL);
	if (!(ptr->nature == DIR_CALL))
		return (NULL);
	if (!ptr->next_token)
		return (NULL);
	if (!(ptr->next_token->nature == LITERAL_NB))
	{
		if (!(ptr->next_token->nature == LABEL_MENTION))
			return (NULL);
		if (!(check_label_mention(ptr->next_token, p)))
			return (NULL);
	}
	return (ptr->next_token->next_token);
}

t_token	*is_ind_call(t_token *ptr, t_parser *p)
{
	if (!(ptr))
		return (NULL);
	if (!(ptr->nature == LITERAL_NB))
	{
		if (!(ptr->nature == LABEL_MENTION))
			return (NULL);
		if (!(check_label_mention(ptr, p)))
			return (NULL);
	}
	return (ptr->next_token);
}

int		is_newline2(t_token *ptr)
{
	if (!(ptr))
		return (0);
	if (!(ptr->nature == NEWLINE))
		return (0);
	if (!(ptr->next_token))
		return (1);
	return (0);
}
