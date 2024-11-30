/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 23:20:57 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/30 23:30:02 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_case(t_stack *s, int values[3])
{
	int	i;

	i = 0;
	while (i < 3)
		if (s->values[i] != values[i])
			return (0);
	return (1);
}

static int	use_special_cases(t_stack *s)
{
	if (s->len != 3)
		return (0);
	if (is_case(s, (int []){1, 2, 0}))
	{
		ft_putstr("rra\n");
		return (1);
	}
	if (is_case(s, (int []){2, 1, 0}))
	{
		ft_putstr("sa\nrra\n");
		return (1);
	}
	return (0);
}

void	resolve(t_stack *stack)
{
	if (use_special_cases(stack))
		return ;
	split_a(stack, stack->len);
	optimize(stack);
}
