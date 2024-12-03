/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 17:21:54 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int		len;
	int		cursor;
	int		*values;
	char	*sequence;
	char	*logger;
	int		alloced;
}	t_stack;

void	stack_clean(t_stack *stack);
void	stack_init(t_stack *stack, int count, char **elements);

void	move_log(t_stack *stack, char *move);
void	move_sa(t_stack *stack);
void	move_sb(t_stack *stack);
void	move_ss(t_stack *stack);
void	move_pa(t_stack *stack);
void	move_pb(t_stack *stack);
void	move_ra(t_stack *stack);
void	move_rb(t_stack *stack);
void	move_rr(t_stack *stack);
void	move_rra(t_stack *stack);
void	move_rrb(t_stack *stack);
void	move_rrr(t_stack *stack);

void	rotate_left(t_stack *stack, int start, int end);
void	rotate_right(t_stack *stack, int start, int end);

#endif
