/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:54:08 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	swap(t_array *arr, int index_a, int index_b)
{
	int	value;

	value = arr->values[index_a];
	arr->values[index_a] = arr->values[index_b];
	arr->values[index_b] = value;
	update_delta(arr, index_a, index_b);
}

void	swap_a(t_array *arr)
{
	if (arr->len - arr->cursor < 2)
		return ;
	swap(arr, arr->cursor, arr->cursor + 1);
}

void	swap_b(t_array *arr)
{
	if (arr->cursor < 2)
		return ;
	swap(arr, arr->cursor - 2, arr->cursor - 1);
}

void	swap_ab(t_array *arr)
{
	swap_a(arr);
	swap_b(arr);
}
