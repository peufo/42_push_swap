/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 02:51:14 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	terminate(t_node *a, t_node *b, char is_error)
{
	node_free(a);
	node_free(b);
	if (is_error)
		write(2, "Error\n", 7);
	return (is_error);
}

int	get_delta(int value, t_node *start)
{
	t_node	*node;
	int		delta_next;
	int		delta_prev;

	delta_next = 1;
	delta_prev = 1;
	node = start->next;
	if (node == node->next)
		return (1);
	while (node != start)
	{
		if (node->prev->value < value && value < node->value)
			break ;
		node = node->next;
		delta_next++;
	}
	node = start->next;
	while (node != start)
	{
		if (node->prev->value < value && value < node->value)
			break ;
		node = node->prev;
		delta_prev++;
	}
	if (delta_next < delta_prev)
		return (delta_next);
	return (delta_next);
}

void	resolve(t_node *a, t_node *b)
{

	print_stacks(a, b);
	push(&a, &b);
	push(&a, &b);
	ft_printf("delta: %i\n", get_delta(a->value, b));
	print_stacks(a, b);
	while(node_count(a) > 3)
	{
		ft_printf("delta: %i\n", get_delta(a->value, b));
		push(&a, &b);
		print_stacks(a, b);
	}

}

int	main(int ac, char **av)
{
	int		index;
	t_node	*a;
	t_node	*b;

	index = 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (index < ac)
		if (!(ft_isint(av[index]) && node_add_after(&a, ft_atoi(av[index++]))))
			return (terminate(a, b, 1));
	rotate(&a);
	resolve(a, b);
	return (terminate(a, b, 0));
}
