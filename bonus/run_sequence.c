/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sequence.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:16:20 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 18:44:37 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	run_next_move(t_move *moves, t_stack *s)
{
	char	*move;
	int		i;

	move = get_next_line(STDIN_FILENO);
	if (!move)
		return (0);
	i = 0;
	while (i < 11)
	{
		if (!ft_strcmp(moves[i].key, move))
			return (moves[i].move(s), 1);
		i++;
	}
	terminate(s, 1);
	return (0);
}

void	run_sequence(t_stack *s)
{
	t_move	*moves;

	moves = (t_move[]){
	{"sa\n", move_sa},
	{"sb\n", move_sb},
	{"ss\n", move_ss},
	{"pa\n", move_pa},
	{"pb\n", move_pb},
	{"ra\n", move_ra},
	{"rb\n", move_rb},
	{"rr\n", move_rr},
	{"rra\n", move_rra},
	{"rrb\n", move_rrb},
	{"rrr\n", move_rrr},
	};
	while (run_next_move(moves, s))
		;
	return ;
}
