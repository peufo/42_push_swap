/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:48:32 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int		len;
	int		cursor;
	int		*values;
	char	*sequence;
	char	*logger;
}	t_stack;
typedef void	(*t_move)(t_stack *);
typedef struct s_moves
{
	t_move	sa;
	t_move	sb;
	t_move	ss;
	t_move	pa;
	t_move	pb;
	t_move	ra;
	t_move	rb;
	t_move	rr;
	t_move	rra;
	t_move	rrb;
	t_move	rrr;
}	t_moves;

void	print_stack(t_stack *stack);
void	clean_stack(t_stack *stack);
void	init_stack(t_stack *stack, int count, char **elements);

t_moves	get_moves(void);
void	log_move(t_stack *stack, char *move);

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	rotate_reverse_a(t_stack *stack);
void	rotate_reverse_b(t_stack *stack);
void	rotate_reverse_ab(t_stack *stack);

#endif
