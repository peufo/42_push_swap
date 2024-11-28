/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:54:47 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/28 18:08:48 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*str_cut(char *start, char *end)
{
	char	*cut;
	char	*_cut;

	if (!start | !end | (end < start))
		return (0);
	cut = malloc(end - start + 1);
	if (!cut)
		return (0);
	_cut = cut;
	while (start < end)
		*(_cut++) = *(start++);
	*_cut = '\0';
	return (cut);
}

static size_t	get_length(char const *str_origin, char c)
{
	size_t		length;
	char		*str;

	length = 0;
	str = (char *)str_origin;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		length += (!!*str);
		while (*str && *str != c)
			str++;
	}
	return (length);
}

static char	**add_next(char **stack, char *str, char c)
{
	char	*end;

	while (*str && *str == c)
		str++;
	end = str;
	while (*end && *end != c)
		end++;
	if (str == end)
	{
		*stack = (void *)0;
		return (stack);
	}
	*stack = str_cut(str, end);
	if (*stack && add_next(stack + 1, end, c))
		return (stack);
	free(*stack);
	return (0);
}

char	**ft_split(char const *str_origin, char c)
{
	size_t		length;
	char		**stack;

	if (!str_origin)
		return (0);
	length = get_length(str_origin, c);
	stack = malloc(sizeof(*stack) * (length + 1));
	if (!stack)
		return (0);
	if (add_next(stack, (char *)str_origin, c))
		return (stack);
	free(stack);
	return (0);
}
