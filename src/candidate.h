/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   candidate.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:24:39 by jvoisard          #+#    #+#             */
/*   Updated: 2024/11/11 16:50:24 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANDIDATE_H
# define CANDIDATE_H
# define MAX_SEQUENCE_LEN	6
# define MAX_CANDIDATES	5
# include "array/array.h"

typedef struct s_candidate	t_candidate;
struct s_candidate
{
	t_array	arr;
	int		sequence[MAX_SEQUENCE_LEN];
};

t_candidate	next_candidate(t_candidate *parent, t_move *moves, int deep);

#endif
