/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 19:59:38 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_behind_count(t_stack *s, int len)
{
	int	count;
	int	index;

	count = 0;
	index = s->len - 1;
	while (
		is_between(s->values[index], s->cursor, s->cursor + len)
		&& index > s->cursor
	)
	{
		count++;
		index--;
	}
	if (index == s->cursor)
		return (0);
	return (count);
}

static void	pull_before_pivot(t_stack *s, int pivot, int behind_count)
{
	int	min;
	int	max;

	min = s->cursor;
	max = pivot;
	while (s->cursor < pivot)
	{
		while (!is_between(s->values[s->cursor], min, max))
		{
			if (behind_count-- > 0)
				s->moves.rra(s);
			else
				s->moves.ra(s);
		}
		s->moves.pb(s);
	}
}

void	split_a(t_stack *s, int len)
{
	int	pivot;
	int	behind_count;
	int	sub_len;

	sub_len = len / 2;
	pivot = s->cursor + sub_len;
	behind_count = get_behind_count(s, len);
	if (len <= 1)
	{
		while (behind_count-- > 0)
			s->moves.rra(s);
		return ;
	}
	if (len == 2)
	{
		while (behind_count-- > 0)
			s->moves.rra(s);
		if (s->values[s->cursor] > s->values[s->cursor + 1])
			s->moves.sa(s);
		return ;
	}
	pull_before_pivot(s, pivot, behind_count);
	split_a(s, len - sub_len);
}
