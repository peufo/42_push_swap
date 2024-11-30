/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/30 22:25:30 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_120(t_stack *s)
{
	if (s->len != 3)
		return (0);
	return (s->values[0] == 1 && s->values[1] == 2 && s->values[2] == 0);
}

void	resolve(t_stack *stack)
{
	if (is_120(stack))
		return (ft_putstr("rra\n"));
	split_a(stack, stack->len);
	optimize(stack);
	ft_putstr(stack->sequence);
}
