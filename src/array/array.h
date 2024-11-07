/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/07 13:56:55 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_array
{
	int	len;
	int	cursor;
	int	*values;
	int	*delta;
	int	entropy;
}	t_array;

void	print_array(t_array *arr);
void	clean_array(t_array *arr);
void	init_array(t_array *arr, int count, char **elements);
void	copy_array(t_array *src, t_array *dest);
void	update_delta(t_array *arr, int start, int end);
void	update_all_delta(t_array *arr);

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
