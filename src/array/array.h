/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:39:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 22:27:25 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
#include "ft_printf.h"

typedef struct s_array
{
	int	len;
	int	cursor;
	int	*values;
	int	*delta;
}	t_array;

void	print_array(t_array *arr);
void	free_array(t_array *arr);
void	init_array(t_array *arr, int count, char **elements);
void	update_delta(t_array *arr, int start, int end);
void	update_all_delta(t_array *arr);
void	push_a(t_array *arr);
void	push_b(t_array *arr);
void	rotate_ra(t_array *arr);
void	rotate_rb(t_array *arr);
void	rotate_a(t_array *arr);
void	rotate_b(t_array *arr);
void	swap_a(t_array *arr);
void	swap_b(t_array *arr);

#endif
