/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 22:11:04 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	terminate(t_node *a)
{
	free_node(a);
	write(2, "Error\n", 7);
	return (1);
}

int	main(int ac, char **av)
{
	int		index;
	t_node	*a;

	index = 0;
	a = NULL;
	while (index < ac)
		if (!add_node(a, ft_atoi(av[index++])))
			terminate(a);
	ft_printf("HELLO BROOO!\n");
	return (0);
}
