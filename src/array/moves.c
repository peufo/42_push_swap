/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:02 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:47:17 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

t_moves	get_moves()
{
	return ((t_moves) {
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
void	log_move(t_array *arr, char *move)
{
	while (*move)
		*(arr->writer++) = *(move++);
	*(arr->writer++) = '\n';
}