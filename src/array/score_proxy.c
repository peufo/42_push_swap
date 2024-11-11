/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_proximity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:57:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/11 22:30:43 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	get_entropi_sum(t_array *arr, int start, int end)
{
	int	sum;

	sum = 0;
	while (start <= end)
		sum += arr->steps[start++];
	return (sum);
}

void	update_balance(t_array *arr)
{
	int	entropy_a;
	int	entropy_b;
	int	score_center;

	if (!arr->score_entropy)
	{
		arr->score_balance = 0;
		return;
	}
	entropy_a = get_entropi_sum(arr, 0, arr->cursor - 1);
	entropy_b = get_entropi_sum(arr, arr->cursor, arr->len - 1);
	if (entropy_a > entropy_b)
		score_center = entropy_a - entropy_b;
	else
		score_center = entropy_b - entropy_a;
	arr->score_balance = score_center;
}
