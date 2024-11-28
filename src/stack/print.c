/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:52:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:18:23 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

#define COL "%4d"

static void	print_n(char *str, int n)
{
	while (n-- > 0)
		ft_printf(str);
}

void	stack_print(t_stack *stack)
{
	int	index;

	print_n("    ", stack->cursor);
	ft_printf("👇");
	index = 0;
	while (index < stack->len)
		ft_printf(COL, stack->values[index++]);
	ft_printf("\n");
}
