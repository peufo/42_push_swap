/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:52:40 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/29 01:31:50 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_ra(t_stack *stack)
{
	rotate_right(stack, stack->cursor, stack->len - 1);
	move_log(stack, "ra");
}

void	move_rb(t_stack *stack)
{
	rotate_left(stack, 0, stack->cursor - 1);
	move_log(stack, "rb");
}

void	move_rr(t_stack *stack)
{
	rotate_right(stack, stack->cursor, stack->len - 1);
	rotate_left(stack, 0, stack->cursor - 1);
	move_log(stack, "rr");
}
