/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 17:47:57 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_array
{
	int		len;
	int		cursor;
	int		*values;
	char	*sequence;
	char	*writer;
}	t_array;
typedef void	(*t_move)(t_array *);
typedef struct s_moves
{
	t_move sa; 
	t_move sb; 
	t_move ss; 
	t_move pa; 
	t_move pb; 
	t_move ra; 
	t_move rb; 
	t_move rr; 
	t_move rra; 
	t_move rrb; 
	t_move rrr; 
}	t_moves;

void	print_array(t_array *arr);
void	clean_array(t_array *arr);
void	init_array(t_array *arr, int count, char **elements);

t_moves	get_moves();
void	log_move(t_array *arr, char *move);

void	swap_a(t_array *arr);
void	swap_b(t_array *arr);
void	swap_ab(t_array *arr);
void	push_a(t_array *arr);
void	push_b(t_array *arr);
void	rotate_a(t_array *arr);
void	rotate_b(t_array *arr);
void	rotate_ab(t_array *arr);
void	rotate_reverse_a(t_array *arr);
void	rotate_reverse_b(t_array *arr);
void	rotate_reverse_ab(t_array *arr);

#endif
