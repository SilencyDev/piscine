/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_election.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:40:17 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/18 22:24:26 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <stdlib.h>
#include "presolve.h"

int			is_solved_puzzle(t_puzzle *puzzle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (puzzle->p[i][j++] == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

t_puzzle	*ft_init(void)
{
	t_puzzle	*puzzle;
	int			i;
	int			j;

	i = 0;
	puzzle = malloc(sizeof(t_puzzle));
	puzzle->row = 0;
	puzzle->col = 0;
	puzzle->next_value = 0;
	puzzle->previous = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			puzzle->p[i][j++] = 0;
		i++;
	}
	return (puzzle);
}

t_puzzle	*ft_election(int clues[16])
{
	t_puzzle	*puzzle;

	puzzle = ft_init();
	ft_presolve_simple_on_col(puzzle, clues);
	ft_presolve_simple_on_row(puzzle, clues);
	ft_presolve_pair_on_col(puzzle, clues);
	ft_presolve_pair_on_row(puzzle, clues);
	return (puzzle);
}
