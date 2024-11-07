/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:52:40 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:58:47 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	rotate(t_array *arr, int start, int end)
{
	int	value;
	int	i;

	i = start;
	value = arr->values[i];
	while (i < end)
	{
		arr->values[i] = arr->values[i + 1];
		i++;
	}
	arr->values[i] = value;
	update_delta(arr, start, end);
}

void	rotate_a(t_array *arr)
{
	rotate(arr, arr->cursor, arr->len - 1);
}

void	rotate_b(t_array *arr)
{
	rotate(arr, 0, arr->cursor - 1);
}

void	rotate_ab(t_array *arr)
{
	rotate_a(arr);
	rotate_b(arr);
}
