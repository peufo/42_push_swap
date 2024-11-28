/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:09:29 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:42:31 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

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
		return (clean_array(arr));
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
	arr->sequence = ft_calloc(count * 20, 4);
	arr->writer = arr->sequence;
	if (!arr->values || !arr->sequence)
		return (clean_array(arr));
	index = 0;
	while (index < count)
	{
		if (!ft_isint(elements[index]))
			return (clean_array(arr));
		arr->values[index] = ft_atoi(elements[index]);
		index++;
	}
	set_values_as_indexes(arr);
}

void	clean_array(t_array *arr)
{
	if (arr->values)
		free(arr->values);
	if (arr->sequence)
		free(arr->sequence);
	return ;
}
