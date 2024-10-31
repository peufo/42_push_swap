/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:57:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/30 00:38:41 by jvoisard         ###   ########.fr       */
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

typedef struct s_node	t_node;
struct s_node
{
	int		value;
	t_node	*next;
	t_node	*prev;
};
t_node	*node_add_after(t_node **node, int value);
t_node	*node_add_before(t_node **node, int value);
void	node_remove(t_node **node);
void	node_free(t_node *node);
int		node_count(t_node *start);
void	swap(t_node *node);
void	push(t_node **from, t_node **to);
void	rotate(t_node **node);
void	rotate_reverse(t_node **node);

void	print_stacks(t_node *a, t_node *b);

#endif
