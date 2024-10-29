/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:20:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 00:26:04 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *node)
{
	int	value;

	if (!node || node->prev == node->next)
		return ;
	value = node->value;
	node->value = node->next->value;
	node->next->value = value;
}

void	push(t_node **from, t_node **to)
{
	if (!*from)
		return ;
	node_add_before(to, (*from)->value);
	node_remove(from);
}

void	rotate(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->next;
}

void	rotate_reverse(t_node **node)
{
	if (!*node)
		return ;
	*node = (*node)->prev;
}
