/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:20 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/11 18:44:20 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	update_alignement(t_array *arr)
{
	int	i;
	int	sum;

	if (!arr->score_alignement)
	{
		arr->score_alignement = 0;
		return;
	}
	sum = 0;
	i = 0;
	while (i < arr->len)
		sum += arr->delta[i++];
	if (sum < 0)
		sum = -sum;
	arr->score_alignement = (sum / arr->len);
}

void	update_score(t_array *arr)
{
	update_entropy(arr);
	update_proximity(arr);
	update_alignement(arr);
	arr->score = (1000 * arr->score_entropy);
	arr->score += (200 * arr->score_proximity);
	arr->score += (10 * arr->score_alignement);
	if (!arr->score_entropy)
	{
		arr->score += (10 * arr->cursor);
	}
}
