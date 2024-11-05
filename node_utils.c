/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:12:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/05 16:24:40 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_print(t_node *start, char *name)
{
	t_node	*node;

	if (!start)
	{
		ft_printf("%3s:\n", name);
		return ;
	}

	ft_printf("%3s: %4i", name, start->value);
	node = start->next;
	while (node != start)
	{
		ft_printf(" %4i", node->value);
		node = node->next;
	}

	ft_printf("\n%3s: %4i", "pos", start->pos);
	node = start->next;
	while (node != start)
	{
		ft_printf(" %4i", node->pos);
		node = node->next;
	}

	ft_printf("\n%3s: %4i", "del", start->delta);
	node = start->next;
	while (node != start)
	{
		ft_printf(" %4i", node->delta);
		node = node->next;
	}

	ft_printf("\n");
}

void	print_stacks(t_node *a, t_node *b)
{
	node_print(a, "A");
	node_print(b, "B");
	ft_printf("\n");
}
