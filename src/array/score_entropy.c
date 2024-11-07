/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_entropy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:58:09 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 19:02:28 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	get_step(t_array *arr, int a, int b)
{
	int	step_a;
	int	step_b;

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

void	update_entropy(t_array *arr)
{
	int	i;
	int	entropy;

	i = 0;
	entropy = get_step(arr, arr->delta[0], arr->delta[arr->len - 1]);
	while (i < arr->len - 1)
	{
		entropy += get_step(arr, arr->delta[i], arr->delta[i + 1]);
		i++;
	}
	arr->score_entropy = entropy;
}