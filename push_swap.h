/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:57:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/29 22:06:41 by jvoisard         ###   ########.fr       */
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
t_node	*add_node(t_node *node, int value);
void	free_node(t_node *node);

#endif
