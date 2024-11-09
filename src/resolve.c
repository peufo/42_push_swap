/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/09 23:44:33 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_array *arr)
{
	t_move		moves[11];
	char		moves_keys[11][4];
	t_candidate	next;
	int			i;

	init_moves(moves);
	init_moves_keys(moves_keys);
	print_array(arr);
	next = (t_candidate){
		.arr = *arr,
		.sequence = { [0 ... MAC_SEQUENCE_LEN - 1] = -1 }
	};
	next = next_candidate(&next, moves, 0);
	i = 0;
	while (i < MAC_SEQUENCE_LEN && next.sequence[i] != -1)
	{
		ft_printf("move: %s\n", moves_keys[next.sequence[i]]);
		moves[next.sequence[i]](arr);
		update_score(arr);
		print_array(arr);
		i++;
	}
}
