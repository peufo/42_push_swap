/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:49 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/29 01:31:09 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_rra(t_stack *stack)
{
	rotate_left(stack, stack->cursor, stack->len - 1);
	move_log(stack, "rra");
}

void	move_rrb(t_stack *stack)
{
	rotate_right(stack, 0, stack->cursor - 1);
	move_log(stack, "rrb");
}

void	move_rrr(t_stack *stack)
{
	rotate_left(stack, stack->cursor, stack->len - 1);
	rotate_right(stack, 0, stack->cursor - 1);
	move_log(stack, "rrr");
}
