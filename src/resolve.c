/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 21:59:37 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 22:52:47 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_array *arr)
{
	print_array(arr);

	push_b(arr);
	push_b(arr);
	push_b(arr);
	print_array(arr);

	swap_a(arr);
	swap_b(arr);
	print_array(arr);
}