/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reducer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:48:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/05 16:10:20 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_reducer_arg
{
	t_node	*start;
	t_node	*current;
	int		index;
} t_reducer_arg;

static void	node_reduce(
	t_node *node,
	void *acc,
	void (*f)(t_reducer_arg *, void *)
)
{
	t_reducer_arg	arg;

	if (!node)
		return ;
	arg.start = node;
	arg.current = arg.start->next;
	arg.index = 1;
	while (arg.current != node)
	{
		f(&arg, acc);
		arg.current = arg.current->next;
		arg.index++;
	}
	arg.index = 0;
	f(&arg, acc);
	return ;
}

static void	node_count_reducer(t_reducer_arg *arg, void *acc)
{
	(void)arg;
	(*(int *)acc)++;
}

int	node_count(t_node *node)
{
	int	count;

	count = 0;
	node_reduce(node, &count, node_count_reducer);
	return (count);
}

static void	node_add_pos_reducer(t_reducer_arg *arg, void *acc)
{
	if (arg->current == arg->start)
	{
		arg->current->pos = *(int *)acc;
		return ;
	}
	if (arg->current->value < arg->start->value)
		(*(int *)acc)++;
}

static void	node_set_delta_reducer(t_reducer_arg *arg, void *acc)
{
	int	count;
	int	total_count;
	int	delta;

	total_count = *(int *)acc;
	count = 0;
	node_reduce(arg->current, &count, node_add_pos_reducer);
	delta = arg->current->pos - arg->index;
	if (delta > 0 && delta > -(delta - total_count))
		delta -= total_count;
	else if (delta < 0 && -delta > (delta + total_count))
		delta += total_count;
	arg->current->delta = delta;
}

void	node_set_delta(t_node *node)
{
	int	total_count;

	total_count = node_count(node);
	node_reduce(node, &total_count, node_set_delta_reducer);
}
