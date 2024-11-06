/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:55:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/06 22:27:25 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	terminate(t_array *arr, char is_error)
{
	free_array(arr);
	if (is_error)
		write(2, "Error\n", 7);
	return (is_error);
}

static int	get_elements_count(char **elements)
{
	int	count;

	count = 0;
	while (elements[count])
		count++;
	return (count);
}

int	main(int ac, char **av)
{
	t_array	arr;
	int		count;
	char	**elements;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		elements = ft_split(av[1], ' ');
		count = get_elements_count(elements);
	}
	else
	{
		elements = av + 1;
		count = ac - 1;
	}
	init_array(&arr, count, elements);
	if (!arr.values)
		terminate(&arr, 1);
	resolve(&arr);
	return (terminate(&arr, 0));
}
