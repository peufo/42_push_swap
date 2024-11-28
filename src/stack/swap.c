/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:17:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	swap_a(t_stack *stack)
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

static void	swap_b(t_stack *stack)
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

void	move_sa(t_stack *stack)
{
	swap_a(stack);
	move_log(stack, "sa");
}

void	move_sb(t_stack *stack)
{
	swap_b(stack);
	move_log(stack, "sb");
}

void	move_ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	move_log(stack, "ss");
}
