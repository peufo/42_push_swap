/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delta.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:32:35 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 23:27:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	update_delta(t_array *arr, int start, int end)
{
	int	delta;

	while (start <= end)
	{
		delta = arr->values[start] - (start - arr->cursor);
		
		if (delta < 0)
			delta += arr->len;
		if (delta > -(delta - arr->len))
			delta -= arr->len;
		arr->delta[start] = delta;
		start++;
	}
}

void	update_all_delta(t_array *arr)
{
	update_delta(arr, 0, arr->len - 1);
}

