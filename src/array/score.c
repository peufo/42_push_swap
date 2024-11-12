/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:50:20 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/12 11:46:54 by jvoisard         ###   ########.fr       */
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
		if (arr->delta[i] > 0)
			sum += arr->delta[i++];
		else
			sum -= arr->delta[i++];
	arr->score_alignement = (sum / arr->len);
}

static void	update_proximity(t_array *arr)
{
	int	i;
	int	proximity;
	
	if (!arr->score_entropy)
	{
		arr->score_proximity = 0;
		return ;
	}
	proximity = INT_MAX;
	if (arr->cursor > 0)
	{
		i = 0;
		while (i < arr->cursor && !arr->steps[i])
			i++;
		if (i < arr->cursor)
			proximity = i;
		i = arr->cursor - 1;
		while (i > 0 && !arr->steps[i])
			i--;
		if (i > 0 && proximity > arr->cursor - i)
			proximity = arr->cursor - i;
	}
	if (arr->cursor < arr->len - 1)
	{
		i = arr->cursor;
		while (i < arr->len && !arr->steps[i])
			i++;
		if (i < arr->len && proximity > i - arr->cursor)
			proximity = i - arr->cursor;
		i = arr->len - 1;
		while (i > arr->cursor && !arr->steps[i])
			i--;
		if (i > arr->cursor && proximity > arr->len - i - 1)
			proximity = arr->len - i - 1;
	}
	arr->score_proximity = proximity;
}

void	update_score(t_array *arr)
{
	update_entropy(arr);
	update_balance(arr);
	update_proximity(arr);
	update_alignement(arr);
	arr->score = (1000 * arr->score_entropy);
	arr->score += (100 * arr->score_balance);
	arr->score += (5 * arr->score_alignement);
	arr->score += (5 * arr->score_proximity);
	if (!arr->score_entropy)
	{
		arr->score += (10 * arr->cursor);
	}
}
