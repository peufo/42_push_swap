/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 00:24:58 by jvoisard         ###   ########.fr       */
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
	print_stacks(a, b);
	swap(a);
	print_stacks(a, b);
	push(&a, &b);
	print_stacks(a, b);
	push(&a, &b);
	print_stacks(a, b);
	push(&a, &b);
	print_stacks(a, b);
	return (terminate(a, b, 0));
}
