/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/02 15:44:52 by jvoisard         ###   ########.fr       */
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

	min = pivot;
	max = s->cursor;
	while (s->cursor > pivot)
	{
		while (!is_between(s->values[s->cursor - 1], min, max))
		{
			if (behind_count-- > 0)
				move_rrb(s);
			else
				move_rb(s);
		}
		move_pa(s);
	}
}

static void	handle_under_len_3(t_stack *s, int len, int behind_count)
{
	if (len <= 1)
	{
		while (behind_count-- > 0)
			move_rrb(s);
		move_pa(s);
		return ;
	}
	if (len == 2)
	{
		while (behind_count-- > 0)
			move_rrb(s);
		if (s->values[s->cursor - 2] > s->values[s->cursor - 1])
			move_sb(s);
		move_pa(s);
		move_pa(s);
		return ;
	}
}

void	split_b(t_stack *s, int len)
{
	int	pivot;
	int	behind_count;
	int	sub_len;

	sub_len = len / 2;
	pivot = s->cursor - sub_len;
	check_swap(s);
	behind_count = get_behind_count(s, len);
	if (len < 3)
		return (handle_under_len_3(s, len, behind_count));
	pull_before_pivot(s, pivot, behind_count);
	split_a(s, sub_len);
	split_b(s, len - sub_len);
}
