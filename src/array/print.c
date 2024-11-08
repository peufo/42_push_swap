/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:52:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 19:07:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

#define COL "%4d"

static void	print_n(char *str, int n)
{
	while (n-- > 0)
		ft_printf(str);
}

static void	print_delta(int index, int delta, int len)
{
	if (!delta)
	{
		print_n(" ", index * 4 + 3);
		ft_printf("◦\n");
		return ;
	}
	if (delta > 0)
	{
		print_n(" ", index * 4 + 3);
		ft_printf("└");
		print_n("─", delta * 4 - 1);
		ft_printf("▷\n");
		return ;
	}
	if (-delta > index)
		index += len;
	print_n(" ", (index + delta) * 4 + 3);
	ft_printf("◁");
	print_n("─", -delta * 4 - 1);
	ft_printf("┘\n");
}

void	print_array(t_array *arr)
{
	int	index;

	print_n("    ", arr->cursor);
	ft_printf("👇 (%d)\n", arr->score);
	index = 0;
	while (index < arr->len)
		ft_printf(COL, arr->values[index++]);
	ft_printf("\n");
	index = 0;
	while (index < arr->len)
		ft_printf(COL, arr->delta[index++]);
	ft_printf("\n");
	index = 0;
	while (index < arr->len)
	{
		print_delta(index, arr->delta[index], arr->len);
		index++;
	}
	ft_printf("\n");
}
