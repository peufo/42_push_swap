/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:19:00 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_between(int v, int min, int max)
{
	return (min <= v && v < max);
}

static int	get_behind_count(t_stack *s, int len)
{
	int	index;
	int	min;
	int	max;

	index = 0;
	min = s->cursor - len;
	max = s->cursor;
	while (is_between(s->values[index], min, max) && index < s->cursor - 1)
		index++;
	if (index == s->cursor - 1)
		return (0);
	return (index);
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

void	split_b(t_stack *s, int len)
{
	int	pivot;
	int	behind_count;
	int	sub_len;

	sub_len = len / 2;
	pivot = s->cursor - sub_len;
	behind_count = get_behind_count(s, len);
    if (len <= 1)
	{
        while (behind_count-- > 0)
			move_rrb(s);
		move_pa(s);
        return ;
    }
    if (len == 2) {
        while (behind_count-- > 0)
			move_rrb(s);
        if (s->values[s->cursor - 2] > s->values[s->cursor - 1])
			move_sb(s);
		move_pa(s);
		move_pa(s);
        return ;
    }
	pull_before_pivot(s, pivot, behind_count);
	split_a(s, len - sub_len);
}
