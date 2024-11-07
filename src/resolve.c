/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 18:29:42 by jvoisard         ###   ########.fr       */
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
		if (move == -1)
			move = i;
		if (scores[i] < scores[move])
			move = i;
		i++;
	}
	if (move == -1)
		return (move);
	scores[move] = -1;
	return (move);
}

static void	select_candidates(int candidates[MAX_CANDIDATES], int scores[11])
{
	int	i;

	i = 0;
	while (i < MAX_CANDIDATES)
		candidates[i++] = get_better_move(scores);
}

static void	next_sequence(t_sequence_ctx ctx, t_array *arr, int index)
{
	t_array	clone;
	int		scores[11];
	int		candidates[MAX_CANDIDATES];
	int		i;

	clone.delta = NULL;
	clone.values = NULL;
	i = 0;
	while (i < 11)
	{
		copy_array(arr, &clone);
		ctx.moves[i](&clone);
		update_score(&clone);
		scores[i] = clone.score - ctx.score_origin;
		i++;
	}
	select_candidates(candidates, scores);
	if (index == MAX_SEQUENCE_SIZE - 1)
	{
		ctx.sequence[index] = candidates[0];
		return ;
	}
	i = 0;
	while (i < MAX_CANDIDATES)
	{
		if (candidates[i] != -1)
		{
			ctx.sequence[index] = candidates[i];
			next_sequence(ctx, &clone, index + 1);
		}
		i++;
	}
	clean_array(&clone);
}

void	resolve(t_array *arr)
{
	t_move	moves[11];
	char	moves_keys[11][4];
	int		sequence[MAX_SEQUENCE_SIZE];
	int		i;

	init_moves(moves);
	init_moves_keys(moves_keys);
	next_sequence((t_sequence_ctx){ 
		.moves = moves,
		.score_origin = arr->score,
		.sequence = sequence}, arr, 0);
	i = 0;
	print_array(arr);
	while (i < MAX_SEQUENCE_SIZE)
	{
		ft_printf("move: %s\n", moves_keys[sequence[i]]);
		moves[sequence[i]](arr);
		print_array(arr);
		i++;
	}
}
