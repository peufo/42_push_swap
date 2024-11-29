/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:29:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/29 01:30:05 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_left(t_stack *stack, int start, int end)
{
	int	value;
	int	i;

	i = end;
	value = stack->values[i];
	while (i > start)
	{
		stack->values[i] = stack->values[i - 1];
		i--;
	}
	stack->values[i] = value;
}

void	rotate_right(t_stack *stack, int start, int end)
{
	int	value;
	int	i;

	i = start;
	value = stack->values[i];
	while (i < end)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = value;
}