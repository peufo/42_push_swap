/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:57:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/30 23:21:31 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "stack/stack.h"
# include "math.h"

typedef struct s_replacer
{
	char	*stupid;
	char	*better;
}	t_replacer;

void	resolve(t_stack *stack);
void	optimize(t_stack *s);
void	split_a(t_stack *s, int len);
void	split_b(t_stack *s, int len);

#endif
