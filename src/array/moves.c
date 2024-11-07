/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:01:02 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 23:20:06 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	init_moves(t_move moves[11])
{
	moves[0] = swap_a;
	moves[1] = swap_b;
	moves[2] = swap_ab;
	moves[3] = push_a;
	moves[4] = push_b;
	moves[5] = rotate_a;
	moves[6] = rotate_b;
	moves[7] = rotate_ab;
	moves[8] = rotate_reverse_a;
	moves[9] = rotate_reverse_b;
	moves[10] = rotate_reverse_ab;
}

void	init_moves_keys(char moves_keys[11][4])
{
	ft_strcpy(moves_keys[0], "sa");
	ft_strcpy(moves_keys[1], "sb");
	ft_strcpy(moves_keys[2], "ss");
	ft_strcpy(moves_keys[3], "pa");
	ft_strcpy(moves_keys[4], "pb");
	ft_strcpy(moves_keys[5], "ra");
	ft_strcpy(moves_keys[6], "rb");
	ft_strcpy(moves_keys[7], "rr");
	ft_strcpy(moves_keys[8], "rra");
	ft_strcpy(moves_keys[9], "rrb");
	ft_strcpy(moves_keys[10], "rrr");
}
