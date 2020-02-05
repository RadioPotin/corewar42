/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_hashtable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapinto <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:53:22 by dapinto           #+#    #+#             */
/*   Updated: 2019/11/27 14:42:39 by dapinto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				rot_hash(char *label)
{
	unsigned long	hash;
	size_t			i;
	size_t			len;

	i = 0;
	hash = 5381;
	len = ft_strlen(label) - 1;
	while (i < len)
		hash = ((hash << 5) + hash) + label[i++];
	return (ft_abs(hash % HASHTABLE_SIZE));
}

static t_hash	*create_collision(t_token *token)
{
	t_hash *node;

	if (!(node = ft_memalloc(sizeof(t_hash))))
		return (NULL);
	if (!(node->label_name = ft_strdup(token->content)))
		return (NULL);
	node->instr_ptr = token;
	return (node);
}

static t_hash	*handle_collisions(t_hash *hash, t_token *token)
{
	t_hash *ptr;

	ptr = hash;
	while (ptr->next_col)
		ptr = ptr->next_col;
	if (!(ptr->next_col = create_collision(token)))
		return (NULL);
	return (ptr->next_col);
}

static int		assign(t_parser *box, int i, t_token *token)
{
	t_hash *ptr;

	ptr = &box->labels[i];
	if (ptr->label_name == NULL)
	{
		if (!(ptr->label_name = ft_strdup(token->content)))
			return (-1);
		ptr->instr_ptr = token;
	}
	else if (!(ptr = handle_collisions(ptr, token)))
		return (-1);
	return (0);
}

int				hash_label_declaration(t_parser *box, t_token *ptr)
{
	int i;

	if (!box->labels)
		if (!(box->labels = ft_memalloc(sizeof(t_hash) * HASHTABLE_SIZE)))
			return (-1);
	i = rot_hash(ptr->content);
	if (assign(box, i, ptr) == -1)
		return (-1);
	return (0);
}
