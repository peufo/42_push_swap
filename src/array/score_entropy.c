/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_entropy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:58:09 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/08 00:01:05 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	get_step(t_array *arr, int index_a, int index_b)
{
	int	a;
	int	b;
	int	step_a;
	int	step_b;

	a = arr->delta[index_a];
	b = arr->delta[index_b];
	if (a == b)
		return (0);
	if (a > b)
	{
		step_a = a - b;
		step_b = b - a + arr->len;
	}
	else
	{
		step_a = b - a;
		step_b = a - b + arr->len;
	}
	if (step_a < step_b)
		return (step_a);
	return (step_b);
}

static void	update_steps(t_array *arr)
{
	int	i;

	if (arr->cursor > 0)
	{
		arr->steps[0] = get_step(arr, 0, arr->cursor - 1);
		i = 1;
		while (i < arr->cursor)
		{
			arr->steps[i] = get_step(arr, i, i - 1);
			i++;
		}
	}
	if (arr->cursor < arr->len)
	{
		arr->steps[arr->cursor] = get_step(arr, arr->cursor, arr->len - 1);
		i = arr->cursor + 1;
		while (i < arr->len)
		{
			arr->steps[i] = get_step(arr, i, i - 1);
			i++;
		}
	}
}

void	update_entropy(t_array *arr)
{
	int	i;
	int	entropy;

	update_steps(arr);
	i = 0;
	entropy = 0;
	while (i < arr->len)
		entropy += arr->steps[i++];
	arr->score_entropy = entropy;
}
