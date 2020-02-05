/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 11:42:32 by dapinto           #+#    #+#             */
/*   Updated: 2020/01/17 13:44:13 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			free_token(t_token *ptr)
{
	if (ptr)
	{
		if (ptr->content)
			ft_strdel(&ptr->content);
		free(ptr);
		ptr = NULL;
	}
}

void			free_fields(char **s1, char **s2, char **s3, char **s4)
{
	if (s1)
		ft_strdel(s1);
	if (s2)
		ft_strdel(s2);
	if (s3)
		ft_strdel(s3);
	if (s4)
		ft_strdel(s4);
}

static void		free_hashtable(t_parser **box)
{
	int		i;
	t_hash	*ptr;
	t_hash	*ptr2;
	t_hash	*hash;

	i = 0;
	while (i < HASHTABLE_SIZE)
	{
		if ((*box)->labels[i].label_name)
		{
			hash = &(*box)->labels[i];
			ptr = hash->next_col;
			while (ptr)
			{
				ptr2 = ptr->next_col;
				ft_strdel(&ptr->label_name);
				free(ptr);
				ptr = ptr2;
			}
			ft_strdel(&hash->label_name);
		}
		i++;
	}
	free((*box)->labels);
}

static void		free_code(t_token **head)
{
	t_token *head_ptr;
	t_token *token_ptr;

	while (*head)
	{
		head_ptr = *head;
		*head = (*head)->next_head;
		if (head_ptr)
			while (head_ptr)
			{
				token_ptr = head_ptr;
				head_ptr = head_ptr->next_token;
				free_token(token_ptr);
			}
		free(head_ptr);
	}
	head = NULL;
}

int				free_all(t_parser *parse)
{
	if (parse->file)
		ft_strdel(&parse->file);
	if (parse->code)
		free_code(&parse->code);
	if (parse->labels)
		free_hashtable(&parse);
	if (parse->bytes_to_write)
		free(parse->bytes_to_write);
	return (-1);
}
