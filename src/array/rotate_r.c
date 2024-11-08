/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:49 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:59:27 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	rotate_reverse(t_array *arr, int start, int end)
{
	int	value;
	int	i;

	i = end;
	value = arr->values[i];
	while (i > start)
	{
		arr->values[i] = arr->values[i - 1];
		i--;
	}
	arr->values[i] = value;
	update_delta(arr, start, end);
}

void	rotate_reverse_a(t_array *arr)
{
	rotate_reverse(arr, arr->cursor, arr->len - 1);
}

void	rotate_reverse_b(t_array *arr)
{
	rotate_reverse(arr, 0, arr->cursor - 1);
}

void	rotate_reverse_ab(t_array *arr)
{
	rotate_reverse_a(arr);
	rotate_reverse_b(arr);
}
