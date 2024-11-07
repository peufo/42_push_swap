/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:19:44 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 22:26:54 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static int	*copy_values(int len, int *src, int *dest)
{
	int	i;

	if (!dest)
		dest = ft_calloc(len, sizeof(*src));
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

void	copy_array(t_array *src, t_array *dest)
{
	dest->len = src->len;
	dest->cursor = src->cursor;
	dest->score_entropy = src->score_entropy;
	dest->score_proximity = src->score_proximity;
	dest->score_alignement = src->score_alignement;
	dest->score = src->score;
	dest->values = copy_values(src->len, src->values, dest->values);
	dest->delta = copy_values(src->len, src->delta, dest->delta);
	dest->steps = copy_values(src->len, src->steps, dest->steps);
}

void	clean_array(t_array *arr)
{
	if (arr->values)
		free(arr->values);
	if (arr->delta)
		free(arr->delta);
	if (arr->steps)
		free(arr->steps);
	return ;
}
