/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:16:31 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/30 22:56:22 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*str_add(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

static int	is_include(char *str, char *pattern)
{
	while (*pattern)
		if (*(str++) != *(pattern++))
			return (0);
	return (1);
}

static int	use_replacers(t_replacer *replacers, char **writer, char **reader)
{
	while (replacers->stupid)
	{
		if (is_include(*reader, replacers->stupid))
		{
			*writer = str_add(*writer, replacers->better);
			*reader += ft_strlen(replacers->stupid);
			return (1);
		}
		replacers++;
	}
	return (0);
}

static void	replace_patterns(t_stack *s, t_replacer *replacers)
{
	char		*reader;
	char		*writer;

	writer = s->sequence;
	reader = s->sequence;
	while (*reader)
	{
		if (!use_replacers(replacers, &writer, &reader))
		{
			while (*reader && *reader != '\n')
				*(writer++) = *(reader++);
			if (*reader)
				*(writer++) = *(reader++);
		}
	}
	*writer = '\0';
}

void	optimize(t_stack *s)
{
	t_replacer	*replacers;

	replacers = (t_replacer[])
	{
	{.stupid = "pb\npa\n", .better = ""},
	{.stupid = "pa\npb\n", .better = ""},
	{.stupid = "rra\nra\n", .better = ""},
	{.stupid = "rrb\nrb\n", .better = ""},
	{.stupid = "pb\npb\nsb\npa\npa\n", .better = "sa\n"},
	{.stupid = "pa\npa\nsa\npb\npb\n", .better = "sb\n"},
	{.stupid = "sa\nsb\n", .better = "ss\n"},
	{.stupid = "sb\nsa\n", .better = "ss\n"},
	{.stupid = "sa\npa\npa\nsa\n", .better = "ss\npa\npa\n"},
	{.stupid = "sb\npa\npa\nsb\n", .better = "pa\npa\nss\n"},
	{.stupid = "pb\nsb\npa\npa\n", .better = "pa\nsa\n"},
	{.stupid = "pb\nra\npa\n", .better = "sa\nra\n"},
	{.stupid = "sa\nrb\npa\npa\nsa\n", .better = "rb\nss\npa\npa\n"},
	{.stupid = NULL, .better = NULL}
	};
	replace_patterns(s, replacers);
}
