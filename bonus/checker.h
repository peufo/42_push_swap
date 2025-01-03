/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:28:24 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 18:18:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "get_next_line.h"
# include "stack.h"

typedef void	t_move_func(t_stack *stack);
typedef struct s_move
{
	char		*key;
	t_move_func	*move;
}	t_move;

void	run_sequence(t_stack *s);
int		terminate(t_stack *stack, char is_error);

#endif
