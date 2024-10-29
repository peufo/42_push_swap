/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:57:08 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 00:24:21 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*node_create(int value)
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

t_node	*node_add_after(t_node **node, int value)
{
	t_node	*new_node;

	new_node = node_create(value);
	if (!new_node)
		return (0);
	if (!*node)
		return (*node = new_node);
	new_node->prev = *node;
	new_node->next = (*node)->next;
	(*node)->next->prev = new_node;
	(*node)->next = new_node;
	return (*node = new_node);
}

t_node	*node_add_before(t_node **node, int value)
{
	t_node	*new_node;

	new_node = node_create(value);
	if (!new_node)
		return (0);
	if (!*node)
		return (*node = new_node);
	new_node->next = *node;
	new_node->prev = (*node)->prev;
	(*node)->prev->next = new_node;
	(*node)->prev = new_node;
	return (*node = new_node);
}

void	node_remove(t_node **node)
{
	t_node	*next;

	if (!*node)
		return ;
	(*node)->next->prev = (*node)->prev;
	(*node)->prev->next = (*node)->next;
	next = NULL;
	if ((*node) != (*node)->next)
		next = (*node)->next;
	free(*node);
	*node = next;
}

void	node_free(t_node *node)
{
	if (!node || !node->prev)
		return ;
	node->prev = NULL;
	node_free(node->next);
	free(node);
}
