/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:09:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 19:50:58 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	get_indexof(t_stack *stack, int value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < stack->len)
		count += stack->values[i++] < value;
	return (count);
}

static void	set_values_as_indexes(t_stack *stack)
{
	int	*indexes;
	int	index;

	indexes = ft_calloc(stack->len, sizeof(*indexes));
	if (!indexes)
		return (clean_stack(stack));
	index = 0;
	while (index < stack->len)
	{
		indexes[index] = get_indexof(stack, stack->values[index]);
		index++;
	}
	free(stack->values);
	stack->values = indexes;
	return ;
}

void	init_stack(t_stack *stack, int count, char **elements)
{
	int	index;

	stack->cursor = 0;
	stack->len = count;
	stack->values = ft_calloc(count, sizeof(*(stack->values)));
	stack->sequence = ft_calloc(count * 20, 4);
	stack->logger = stack->sequence;
	if (!stack->values || !stack->sequence)
		return (clean_stack(stack));
	index = 0;
	while (index < count)
	{
		if (!ft_isint(elements[index]))
			return (clean_stack(stack));
		stack->values[index] = ft_atoi(elements[index]);
		index++;
	}
	set_moves(stack);
	set_values_as_indexes(stack);
}

void	clean_stack(t_stack *stack)
{
	if (stack->values)
		free(stack->values);
	if (stack->sequence)
		free(stack->sequence);
	return ;
}
