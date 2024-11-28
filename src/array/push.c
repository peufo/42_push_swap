/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:50:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:58:45 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	push_a(t_array *arr)
{
	if (!arr->cursor)
		return ;
	arr->cursor--;
	log_move(arr, "pa");
}

void	push_b(t_array *arr)
{
	if (arr->cursor == arr->len - 1)
		return ;
	arr->cursor++;
	log_move(arr, "pb");
}
