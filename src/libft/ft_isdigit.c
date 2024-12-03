/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:53:41 by jvoisard          #+#    #+#             */
/*   Updated: 2024/12/03 19:08:04 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isint_overflow(char *str)
{
	char	*max;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i < 10)
		return (0);
	if (i > 10)
		return (1);
	i = 0;
	max = "2147483647";
	while (max[i])
	{
		if (str[i] > max[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isint(char *str)
{
	if (!str)
		return (0);
	if (*str == '+' || *str == '-')
		str++;
	if (ft_isint_overflow(str))
		return (0);
	while (*str)
		if (!ft_isdigit(*(str++)))
			return (0);
	return (1);
}
