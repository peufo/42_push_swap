/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:02 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 19:50:34 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	set_moves(t_stack *s)
{
	s->moves.sa = swap_a;
	s->moves.sb = swap_b;
	s->moves.ss = swap_ab;
	s->moves.pa = push_a;
	s->moves.pb = push_b;
	s->moves.ra = rotate_a;
	s->moves.rb = rotate_b;
	s->moves.rr = rotate_ab;
	s->moves.rra = rotate_reverse_a;
	s->moves.rrb = rotate_reverse_b;
	s->moves.rrr = rotate_reverse_ab;
}

void	log_move(t_stack *stack, char *move)
{
	while (*move)
		*(stack->logger++) = *(move++);
	*(stack->logger++) = '\n';
}
