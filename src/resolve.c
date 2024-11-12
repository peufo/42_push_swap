/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/11 23:53:13 by jvoisard         ###   ########.fr       */
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
	int			i;
	int			count;

	init_moves(moves);
	init_moves_keys(moves_keys);
	next.arr = *arr;
	count = 0;
	print_array(arr);
	while (arr->score > 0 && count < 30)
	{
		next.arr = *arr;
		reset_sequence(next.sequence);
		next = next_candidate(&next, moves, 0);
		i = 0;
		//while (i < MAX_SEQUENCE_LEN && next.sequence[i] != -1)
		//{
		ft_printf("%s\n", moves_keys[next.sequence[i]]);
		moves[next.sequence[i]](arr);
		update_score(arr);
		print_array(arr);
		i++;
		count++;
		//}
	}
	ft_printf("FOUND IN %d MOVES\n", count);
}
