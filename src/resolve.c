/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/14 13:02:16 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_sequence(int sequence[MAX_SEQUENCE_LEN])
{
	int	i;

	i = 0;
	while (i < MAX_SEQUENCE_LEN)
		sequence[i++] = -1;
}

void	resolve(t_array *arr)
{
	t_move		moves[11];
	char		moves_keys[11][4];
	t_candidate	next;
	int			count;

	init_moves(moves);
	init_moves_keys(moves_keys);
	count = 0;
	//print_array(arr);
	while (arr->score > 0 && count < 30)
	{
		next.arr = *arr;
		reset_sequence(next.sequence);
		next = next_candidate(&next, moves, 0);
		ft_printf("%s\n", moves_keys[next.sequence[0]]);
		moves[next.sequence[0]](arr);
		update_score(arr);
		//print_array(arr);
		count++;
	}
	ft_printf("FOUND IN %d MOVES\n", count);
}
