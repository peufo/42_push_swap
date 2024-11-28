/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:57:46 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	_swap_a(t_array *arr)
{
	int	value;
	int	a;
	int	b;

	if (arr->len - arr->cursor < 2)
		return ;
	a = arr->cursor;
	b = arr->cursor + 1;
	value = arr->values[b];
	arr->values[a] = arr->values[b];
	arr->values[b] = value;
}
static void	_swap_b(t_array *arr)
{
	int	value;
	int	a;
	int	b;

	if (arr->cursor < 2)
		return ;
	a = arr->cursor - 2;
	b = arr->cursor - 1;
	value = arr->values[b];
	arr->values[a] = arr->values[b];
	arr->values[b] = value;
}

void	swap_a(t_array *arr) {
	_swap_a(arr);
	log_move(arr, "sa");
}

void	swap_b(t_array *arr)
{
	_swap_b(arr);
	log_move(arr, "sb");
}

void	swap_ab(t_array *arr)
{
	_swap_a(arr);
	_swap_b(arr);
	log_move(arr, "ss");
}
