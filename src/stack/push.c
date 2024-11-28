/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:50:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:08:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_a(t_stack *stack)
{
	if (!stack->cursor)
		return ;
	stack->cursor--;
	log_move(stack, "pa");
}

void	push_b(t_stack *stack)
{
	if (stack->cursor == stack->len - 1)
		return ;
	stack->cursor++;
	log_move(stack, "pb");
}
