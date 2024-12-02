/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/02 16:05:21 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_between(int v, int min, int max)
{
	return (min <= v && v < max);
}

static int	get_behind_count(t_stack *s, int len)
{
	int	count;
	int	index;
	int	min;
	int	max;

	count = 0;
	index = s->len - 1;
	min = s->cursor;
	max = s->cursor + len;
	while (is_between(s->values[index], min, max) && index > s->cursor)
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
				move_rra(s);
			else
				move_ra(s);
		}
		move_pb(s);
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
			move_rra(s);
		return ;
	}
	if (len == 2)
	{
		while (behind_count-- > 0)
			move_rra(s);
		if (s->values[s->cursor] > s->values[s->cursor + 1])
			move_sa(s);
		return ;
	}
	check_swap(s);
	pull_before_pivot(s, pivot, behind_count);
	split_a(s, len - sub_len);
	split_b(s, sub_len);
}
