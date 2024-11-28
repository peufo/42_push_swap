/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:52:40 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:08:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate(t_stack *stack, int start, int end)
{
	int	value;
	int	i;

	i = start;
	value = stack->values[i];
	while (i < end)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = value;
}

void	rotate_a(t_stack *stack)
{
	rotate(stack, stack->cursor, stack->len - 1);
	log_move(stack, "ra");
}

void	rotate_b(t_stack *stack)
{
	rotate(stack, 0, stack->cursor - 1);
	log_move(stack, "rb");
}

void	rotate_ab(t_stack *stack)
{
	rotate(stack, stack->cursor, stack->len - 1);
	rotate(stack, 0, stack->cursor - 1);
	log_move(stack, "rr");
}
