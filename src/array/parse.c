/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:09:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 22:27:25 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"
#include "libft.h"

void	free_array(t_array *arr)
{
	if (arr->values)
		free(arr->values);
	if (arr->delta)
		free(arr->delta);
	return ;
}

static int	get_indexof(t_array *arr, int value)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < arr->len)
		count += arr->values[i++] < value;
	return (count);
}

static void	set_values_as_indexes(t_array *arr)
{
	int	*indexes;
	int	index;

	indexes = ft_calloc(arr->len, sizeof(*indexes));
	if (!indexes)
		return (free_array(arr));
	index = 0;
	while (index < arr->len)
	{
		indexes[index] = get_indexof(arr, arr->values[index]);
		index++;
	}
	free(arr->values);
	arr->values = indexes;
	return ;
}

void	init_array(t_array *arr, int count, char **elements)
{
	int	index;

	arr->cursor = 0;
	arr->len = count;
	arr->values = ft_calloc(count, sizeof(*(arr->values)));
	if (!arr->values)
		return ;
	arr->delta = ft_calloc(count, sizeof(*(arr->delta)));
	if (!arr->delta)
		return (free_array(arr));
	index = 0;
	while (index < count)
	{
		if (!ft_isint(elements[index]))
			return (free_array(arr));
		arr->values[index] = ft_atoi(elements[index]);
		index++;
	}
	set_values_as_indexes(arr);
	update_all_delta(arr);
}
