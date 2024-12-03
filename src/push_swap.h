/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:57:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 17:21:37 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "stack/stack.h"

typedef struct s_replacer
{
	char	*stupid;
	char	*better;
}	t_replacer;

void	resolve(t_stack *stack);
void	optimize(t_stack *s);
void	split_a(t_stack *s, int len);
void	split_b(t_stack *s, int len);
void	check_swap(t_stack *s);

#endif
