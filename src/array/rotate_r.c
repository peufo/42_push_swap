/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:54:49 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 19:08:55 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	rotate_r(t_array *arr, int start, int end)
{
	int	value;
	int i;

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

void	rotate_ra(t_array *arr)
{
	rotate_r(arr, arr->cursor, arr->len - 1);
}

void	rotate_rb(t_array *arr)
{
	rotate_r(arr, 0, arr->cursor - 1);
}