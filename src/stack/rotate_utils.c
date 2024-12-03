/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:29:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 18:51:11 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	rotate_left(t_stack *stack, int start, int end)
{
	int	value;
	int	i;

	if (start < 0 || end < 0)
		return ;
	if (start >= stack->len || end >= stack->len)
		return ;
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

	if (start < 0 || end < 0)
		return ;
	if (start >= stack->len || end >= stack->len)
		return ;
	i = start;
	value = stack->values[i];
	while (i < end)
	{
		stack->values[i] = stack->values[i + 1];
		i++;
	}
	stack->values[i] = value;
}
