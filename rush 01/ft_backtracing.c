/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:22:06 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/18 23:12:50 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include <stdlib.h>
#include <stdio.h>

int			is_puzzle_solved(t_puzzle *puzzle)
{
	int j;
	int i;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (puzzle->p[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		puzzle_cpy(t_puzzle *dest, t_puzzle *src)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			dest->p[row][col] = src->p[row][col];
			col++;
		}
		row++;
	}
}

t_puzzle	*create_next_puzzle(t_puzzle *cur_puzzle)
{
	t_puzzle	*next_puzzle;
	int			r;
	int			c;

	next_puzzle = malloc(sizeof(t_puzzle));
	puzzle_cpy(next_puzzle, cur_puzzle);
	r = cur_puzzle->row;
	c = cur_puzzle->col;
	next_puzzle->p[r][c] = cur_puzzle->next_value;
	while (next_puzzle->p[r][c] != 0)
	{
		c++;
		if (c == 4)
		{
			r++;
			c = 0;
		}
	}
	next_puzzle->row = r;
	next_puzzle->col = c;
	next_puzzle->next_value = 0;
	next_puzzle->previous = cur_puzzle;
	return (next_puzzle);
}

t_puzzle	*ft_backtracing(t_puzzle *cur_puzzle, int clues[16])
{
	t_puzzle	*tmp_puzzle;

	cur_puzzle->next_value += 1;
	cur_puzzle = create_next_puzzle(cur_puzzle);
	while (cur_puzzle && (!is_puzzle_solved(cur_puzzle) ||
				!is_puzzle_legal(cur_puzzle, clues)))
	{
		if (is_puzzle_legal(cur_puzzle, clues) && cur_puzzle->next_value < 4)
		{
			cur_puzzle->next_value += 1;
			cur_puzzle = create_next_puzzle(cur_puzzle);
		}
		else
		{
			tmp_puzzle = cur_puzzle->previous;
			free(cur_puzzle);
			cur_puzzle = tmp_puzzle;
		}
	}
	return (cur_puzzle);
}
