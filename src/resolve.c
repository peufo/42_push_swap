/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:47:15 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_a(t_stack *stack, int len)
{
	(void)stack;
	(void)len;
}

void	resolve(t_stack *stack)
{
	t_moves	moves;

	moves = get_moves();
	moves.pa(stack);
	moves.ra(stack);
	moves.pb(stack);
	split_a(stack, stack->len);
	ft_putstr(stack->sequence);
}
