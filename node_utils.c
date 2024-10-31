/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:12:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 00:57:54 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	node_print(t_node *start, char *name)
{
	t_node	*node;

	if (!start)
	{
		ft_printf("%s:\n", name);
		return ;
	}
	ft_printf("%s: %3i", name, start->value);
	node = start->next;
	while (node != start)
	{
		ft_printf(" %3i", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

int	node_count(t_node *start)
{
	t_node	*node;
	int		count;

	if (!start)
		return (0);
	node = start->next;
	count = 1;
	while (node != start)
	{
		node = node->next;
		count++;
	}
	return (count);
}

void	print_stacks(t_node *a, t_node *b)
{
	node_print(a, "A");
	node_print(b, "B");
	ft_printf("\n");
}
