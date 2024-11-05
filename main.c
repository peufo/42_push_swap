/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/05 15:31:36 by jvoisard         ###   ########.fr       */
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

void	resolve(t_node *a, t_node *b)
{
	node_set_delta(a);
	print_stacks(a, b);
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
