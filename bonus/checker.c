/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:18:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 19:37:31 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	terminate(t_stack *stack, char is_error)
{
	stack_clean(stack);
	if (is_error)
		write(2, "Error\n", 7);
	exit(is_error);
}

static int	get_elements_count(char **elements)
{
	int	count;

	count = 0;
	while (elements[count])
		count++;
	return (count);
}

static int	is_sorted(t_stack *s)
{
	int	i;

	if (s->cursor != 0)
		return (0);
	i = 0;
	while (i < s->len - 1)
	{
		if (s->values[i + 1] - s->values[i] != 1)
			return (0);
		i++;
	}
	return (1);
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
	run_sequence(&stack);
	if (is_sorted(&stack))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (terminate(&stack, 0));
}
