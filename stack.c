/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:08 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 22:09:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

t_node	*add_node(t_node *node, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	if (!node)
		return (node = new_node);
	new_node->prev = node;
	new_node->next = node->next;
	node->next->prev = new_node;
	node->next = new_node;
	return (new_node);
}

void	free_node(t_node *node)
{
	if (!node || !node->prev)
		return ;
	node->prev = NULL;
	free_node(node->next);
	free(node);
}
