/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:02 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:43:59 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	move_log(t_stack *stack, char *move)
{
	while (*move)
		*(stack->logger++) = *(move++);
	*(stack->logger++) = '\n';
}
