/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_puzzle_legal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:19:53 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/18 22:58:11 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

int	is_row_legal(t_puzzle *p, int row)
{
	char	ref[10];
	int		j;

	j = 0;
	while (j < 5)
		ref[j++] = 0;
	j = 0;
	while (j < 4)
	{
		if (ref[p->p[row][j]])
			return (0);
		ref[p->p[row][j]] = p->p[row][j];
		j++;
	}
	return (1);
}

int	is_col_legal(t_puzzle *p, int col)
{
	char	ref[10];
	int		i;

	i = 0;
	while (i < 5)
		ref[i++] = 0;
	i = 0;
	while (i < 4)
	{
		if (ref[p->p[i][col]])
			return (0);
		ref[p->p[i][col]] = p->p[i][col];
		i++;
	}
	return (1);
}

int	is_puzzle_legal(t_puzzle *puzzle, int clues[16])
{
	int row;
	int col;

	col = puzzle->previous->col;
	row = puzzle->previous->row;
	if (!is_row_legal(puzzle, row) || !is_col_legal(puzzle, col))
		return (0);
	return (is_respecting_clues(puzzle, clues));
}

int	count_b(int a, int b, int c, int d)
{
	int n;

	n = 1;
	if (b > a)
		n++;
	if (c > b && c > a)
		n++;
	if (d > c && d > b && d > a)
		n++;
	return (n);
}

int	is_respecting_clues(t_puzzle *p, int clues[16])
{
	int row;
	int col;
	int nb1;
	int nb2;

	row = p->previous->row;
	col = p->previous->col;
	if (row == 3)
	{
		nb1 = count_b(p->p[row][0], p->p[row][1], p->p[row][2], p->p[row][3]);
		nb2 = count_b(p->p[row][3], p->p[row][2], p->p[row][1], p->p[row][0]);
		if (!(clues[row + 8] == nb1 && clues[row + 12] == nb2))
			return (0);
	}
	if (col == 3)
	{
		nb1 = count_b(p->p[0][col], p->p[1][col], p->p[2][col], p->p[3][col]);
		nb2 = count_b(p->p[3][col], p->p[2][col], p->p[1][col], p->p[0][col]);
		if (!(clues[col] == nb1 && clues[col + 4] == nb2))
			return (0);
	}
	return (1);
}
