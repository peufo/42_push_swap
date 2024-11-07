/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:50:21 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:58:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	push_a(t_array *arr)
{
	if (!arr->cursor)
		return ;
	arr->cursor--;
	update_all_delta(arr);
}

void	push_b(t_array *arr)
{
	if (arr->cursor == arr->len - 1)
		return ;
	arr->cursor++;
	update_all_delta(arr);
}
