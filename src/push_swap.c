/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 19:24:05 by jvoisard         ###   ########.fr       */
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
		return (terminate(&stack, 1));
	resolve(&stack);
	ft_putstr(stack.sequence);
	return (terminate(&stack, 0));
}
