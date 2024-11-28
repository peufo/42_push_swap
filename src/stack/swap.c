/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:08:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	_swap_a(t_stack *stack)
{
	int	value;
	int	a;
	int	b;

	if (stack->len - stack->cursor < 2)
		return ;
	a = stack->cursor;
	b = stack->cursor + 1;
	value = stack->values[b];
	stack->values[a] = stack->values[b];
	stack->values[b] = value;
}
static void	_swap_b(t_stack *stack)
{
	int	value;
	int	a;
	int	b;

	if (stack->cursor < 2)
		return ;
	a = stack->cursor - 2;
	b = stack->cursor - 1;
	value = stack->values[b];
	stack->values[a] = stack->values[b];
	stack->values[b] = value;
}

void	swap_a(t_stack *stack) {
	_swap_a(stack);
	log_move(stack, "sa");
}

void	swap_b(t_stack *stack)
{
	_swap_b(stack);
	log_move(stack, "sb");
}

void	swap_ab(t_stack *stack)
{
	_swap_a(stack);
	_swap_b(stack);
	log_move(stack, "ss");
}
