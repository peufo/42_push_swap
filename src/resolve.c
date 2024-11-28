/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:40:14 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_array *arr)
{
	t_moves	moves;

	moves = get_moves();

	moves.pa(arr);
	moves.ra(arr);
	moves.pb(arr);

	ft_putstr(arr->sequence);
}
