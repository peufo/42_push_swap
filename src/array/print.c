/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:52:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:02:37 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

#define COL "%4d"

static void	print_n(char *str, int n)
{
	while (n-- > 0)
		ft_printf(str);
}

void	print_array(t_array *arr)
{
	int	index;

	print_n("    ", arr->cursor);
	ft_printf("👇");
	index = 0;
	while (index < arr->len)
		ft_printf(COL, arr->values[index++]);
	ft_printf("\n");
}
