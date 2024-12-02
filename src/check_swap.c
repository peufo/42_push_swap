/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:28:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/02 15:41:04 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_swap(t_stack *s)
{
	int	swap_a;
	int	swap_b;

	swap_a = (s->cursor < s->len - 1
			&& (s->values[s->cursor] - s->values[s->cursor + 1] == 1));
	swap_b = (s->cursor > 1
			&& (s->values[s->cursor - 2] - s->values[s->cursor - 1] == 1));
	if (swap_a && swap_b)
		return (move_ss(s));
	if (swap_a)
		return (move_sa(s));
	if (swap_b)
		return (move_sb(s));
	return ;
}
