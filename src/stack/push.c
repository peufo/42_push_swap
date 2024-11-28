/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:50:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:17:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_pa(t_stack *stack)
{
	if (!stack->cursor)
		return ;
	stack->cursor--;
	move_log(stack, "pa");
}

void	move_pb(t_stack *stack)
{
	if (stack->cursor == stack->len - 1)
		return ;
	stack->cursor++;
	move_log(stack, "pb");
}
