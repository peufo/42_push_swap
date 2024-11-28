/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:18:42 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	terminate(t_stack *stack, char is_error)
{
	stack_clean(stack);
	if (is_error)
		write(2, "Error\n", 7);
	return (is_error);
}

static int	get_elements_count(char **elements)
{
	int	count;

	count = 0;
	while (elements[count])
		count++;
	return (count);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	int		count;
	char	**elements;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		elements = ft_split(av[1], ' ');
		count = get_elements_count(elements);
	}
	else
	{
		elements = av + 1;
		count = ac - 1;
	}
	stack_init(&stack, count, elements);
	if (!stack.values)
		terminate(&stack, 1);
	resolve(&stack);
	return (terminate(&stack, 0));
}
