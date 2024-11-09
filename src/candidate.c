/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 00:40:18 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/09 23:45:14 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "candidate.h"

static void	copy_candidate(t_candidate *src, t_candidate *dest)
{
	int	deep;

	init_empty_array(&(dest->arr));
	copy_array(&(src->arr), &(dest->arr));
	deep = 0;
	while (deep < MAC_SEQUENCE_LEN)
	{
		dest->sequence[deep] = src->sequence[deep];
		deep++;
	}
}

static t_candidate	new_candidate(t_candidate *parent, t_move *moves, int move)
{
	int			deep;
	t_candidate	candidate;

	copy_candidate(parent, &candidate);
	moves[move](&(candidate.arr));
	update_score(&(candidate.arr));
	deep = 0;
	while (deep < MAC_SEQUENCE_LEN && candidate.sequence[deep] != -1)
		deep++;
	candidate.sequence[deep] = move;
	return (candidate);
}

static int	is_selected(t_candidate *candidate, t_candidate **selected)
{
	int	i;

	i = 0;
	while (i < MAX_CANDIDATES)
		if (candidate == selected[i++])
			return (1);
	return (0);
}

static void	select_candidates(t_candidate *candidates, t_candidate **selected)
{
	int	i;
	int	best_score;
	int	selected_index;

	selected_index = 0;
	while (selected_index < MAX_CANDIDATES)
	{
		i = 0;
		best_score = INT_MAX;
		while (i < 11)
		{
			if (!is_selected(candidates + i, selected))
			{
				if (best_score > candidates[i].arr.score)
				{
					selected[selected_index] = (candidates + i);
					best_score = candidates[i].arr.score;
				}
			}
			i++;
		}
		selected_index++;
	}
}

// TODO, CLEAN ALL OTHER ARRAYS WHEN RETURN A VALUE
t_candidate	next_candidate(t_candidate *parent, t_move *moves, int deep)
{
	t_candidate	candidates[11];
	t_candidate	*selected[MAX_CANDIDATES];
	t_candidate	selected_next[MAX_CANDIDATES];
	int			index;
	int			better_candidate;

	index = 0;
	while (index < 11)
	{
		candidates[index] = new_candidate(parent, moves, index);
		index++;
	}
	select_candidates(candidates, selected);
	if (deep == MAC_SEQUENCE_LEN - 1 || selected[0]->arr.score == 0)
		return (*(selected[0]));
	index = 0;
	while (index < MAX_CANDIDATES)
	{
		selected_next[index] = next_candidate(selected[index], moves, deep + 1);
		index++;
	}
	better_candidate = 0;
	index = 0;
	while (index < MAX_CANDIDATES)
	{
		if (selected_next[index].arr.score < selected_next[better_candidate].arr.score)
			better_candidate = index;
		index++;
	}
	return (selected_next[better_candidate]);
}
