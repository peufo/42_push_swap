/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:20 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/10 00:42:29 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static void	update_alignement(t_array *arr)
{
	int	i;
	int	sum;

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
	if (!arr->score_entropy)
		arr->score_proximity = 0;
	else
		update_proximity(arr);
	update_alignement(arr);
	arr->score = (1000 * arr->score_entropy);
	arr->score += (100 * arr->score_proximity);
	arr->score += (10 * arr->cursor);
	arr->score += (1 * arr->score_alignement);
}
