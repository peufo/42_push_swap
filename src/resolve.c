/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 23:23:01 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MAX_SEQUENCE_SIZE	4
#define MAX_CANDIDATES	3

static int	get_better_move(int scores[11])
{
	int	i;
	int	move;

	move = -1;
	i = 0;
	while (i < 11)
	{
		if (scores[i] < 0)
		{
			if (move == -1)
				move = i;
			if (scores[i] < scores[move])
				move = i;
		}
		i++;
	}
	if (move == -1)
		return (move);
	scores[move] = INT_MAX;
	return (move);
}

static void	select_candidates(int candidates[MAX_CANDIDATES], int scores[11])
{
	int	i;

	i = 0;
	while (i < MAX_CANDIDATES)
		candidates[i++] = get_better_move(scores);
}

static int	next_sequence(t_sequence_ctx ctx, t_array *arr, int index)
{
	t_array	clone;
	int		scores[11];
	int		candidates[MAX_CANDIDATES];
	int		i;

	init_empty_array(&clone);
	i = 0;
	while (i < 11)
	{
		copy_array(arr, &clone);
		ctx.moves[i](&clone);
		update_score(&clone);
		scores[i] = clone.score - ctx.score_origin;
		if (clone.score == 0)
		{
			ctx.sequence[index] = i;
			return (0);
		}
		i++;
	}
	select_candidates(candidates, scores);
	if (index == MAX_SEQUENCE_SIZE - 1)
	{
		ctx.sequence[index] = candidates[0];
		return (1);
	}
	i = 0;
	while (i < MAX_CANDIDATES)
	{
		if (candidates[i] != -1)
		{
			copy_array(arr, &clone);
			ctx.moves[candidates[i]](&clone);
			update_score(&clone);
			ctx.sequence[index] = candidates[i];
			if (!next_sequence(ctx, &clone, index + 1))
				return (0);
		}
		i++;
	}
	clean_array(&clone);
	return (1);
}

void	resolve(t_array *arr)
{
	t_move	moves[11];
	char	moves_keys[11][4];
	int		sequence[MAX_SEQUENCE_SIZE];
	int		i;

	i = 0;
	while (i < MAX_SEQUENCE_SIZE)
		sequence[i++] = -1;
	init_moves(moves);
	init_moves_keys(moves_keys);
	next_sequence((t_sequence_ctx){ 
		.moves = moves,
		.score_origin = arr->score,
		.sequence = sequence}, arr, 0);
	print_array(arr);

	sequence[0] = 4;
	sequence[1] = 4;
	sequence[2] = 2;
	sequence[3] = 3;

	i = 0;
	while (i < MAX_SEQUENCE_SIZE)
	{
		if (sequence[i] == -1)
			break;
		ft_printf("move: %s\n", moves_keys[sequence[i]]);
		moves[sequence[i]](arr);
		update_score(arr);
		print_array(arr);
		i++;
	}
}
