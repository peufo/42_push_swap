/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:02 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:47:56 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_moves	get_moves(void)
{
	return ((t_moves){
		.sa = swap_a,
		.sb = swap_b,
		.ss = swap_ab,
		.pa = push_a,
		.pb = push_b,
		.ra = rotate_a,
		.rb = rotate_b,
		.rr = rotate_ab,
		.rra = rotate_reverse_a,
		.rrb = rotate_reverse_b,
		.rrr = rotate_reverse_ab,
	});
}

void	log_move(t_stack *stack, char *move)
{
	while (*move)
		*(stack->logger++) = *(move++);
	*(stack->logger++) = '\n';
}
