/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:49 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:17:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	rotate_reverse(t_stack *stack, int start, int end)
{
	int	value;
	int	i;

	i = end;
	value = stack->values[i];
	while (i > start)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[i] = value;
}

void	move_rra(t_stack *stack)
{
	rotate_reverse(stack, stack->cursor, stack->len - 1);
	move_log(stack, "rra");
}

void	move_rrb(t_stack *stack)
{
	rotate_reverse(stack, 0, stack->cursor - 1);
	move_log(stack, "rrb");
}

void	move_rrr(t_stack *stack)
{
	rotate_reverse(stack, stack->cursor, stack->len - 1);
	rotate_reverse(stack, 0, stack->cursor - 1);
	move_log(stack, "rrr");
}
