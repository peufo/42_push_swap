/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_proxy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:57:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 19:04:08 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

static	int	get_arr_index(t_array *arr, int index)
{
	while (index >= arr->len)
		index -= arr->len;
	return (index);
}

static int	get_proxyimity_up(t_array *arr)
{
	int	index_a;
	int	index_b;
	int	step;
	int	proxy;

	index_a = arr->cursor;
	index_b = get_arr_index(arr, arr->cursor + 1);
	step = arr->delta[index_a] - arr->delta[index_b];
	proxy = 0;
	while (proxy < arr->len && !step)
	{
		proxy++;
		index_a = index_b;
		index_b = get_arr_index(arr, index_b + 1);
		step = arr->delta[index_a] - arr->delta[index_b];
	}
	return (proxy);
}

static int	get_proxyimity_down(t_array *arr)
{
	int	index_a;
	int	index_b;
	int	step;
	int	proxy;

	index_a = arr->cursor;
	index_b = get_arr_index(arr, arr->cursor - 1);
	step = arr->delta[index_a] - arr->delta[index_b];
	proxy = 0;
	while (proxy < arr->len && !step)
	{
		proxy++;
		index_a = index_b;
		index_b = get_arr_index(arr, index_b - 1);
		step = arr->delta[index_a] - arr->delta[index_b];
	}
	return (proxy);
}

void	update_proximity(t_array *arr)
{
	int	proxi_up;
	int	proxi_down;

	proxi_up = get_proxyimity_up(arr);
	proxi_down = get_proxyimity_down(arr);
	if (proxi_up < proxi_down)
		arr->score_proximity = proxi_up;
	else
		arr->score_proximity = proxi_down;
}