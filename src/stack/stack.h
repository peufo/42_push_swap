/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 20:18:42 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack	t_stack;
typedef void			(*t_move)(t_stack *);

struct s_stack
{
	int		len;
	int		cursor;
	int		*values;
	char	*sequence;
	char	*logger;
};

void	stack_print(t_stack *stack);
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

#endif
