/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:52:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:58:38 by jvoisard         ###   ########.fr       */
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

static int	get_delta_diff(t_array *arr, int a, int b)
{
	int	diff_a;
	int	diff_b;

	if (a == b)
		return (0);
	if (a > b)
	{
		diff_a = a - b;
		diff_b = b - a + arr->len;
	}
	else
	{
		diff_a = b - a;
		diff_b = a - b + arr->len;
	}
	if (diff_a < diff_b)
		return (diff_a);
	return (diff_b);
}

void	print_state(t_array *arr)
{
	int	i;
	int	sum_diff;

	i = 0;
	sum_diff = get_delta_diff(arr, arr->delta[0], arr->delta[arr->len - 1]);
	while (i < arr->len - 1)
	{
		sum_diff += get_delta_diff(arr, arr->delta[i], arr->delta[i + 1]);
		i++;
	}
	ft_printf("(%d)\n", sum_diff);
}

void	print_array(t_array *arr)
{
	int	index;

	print_n("    ", arr->cursor);
	ft_printf("👇 ");
	print_state(arr);
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
