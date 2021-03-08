/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presolve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:09:47 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/18 22:23:47 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

void		ft_presolve_simple_on_col(t_puzzle *p, int clues[16])
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (clues[i] == 1)
			p->p[(i > 3) * 3][i % 4] = 4;
		if (clues[i] == 4)
		{
			p->p[3 - 3 * (i < 4)][i % 4] = 1;
			p->p[2 - (i < 4)][i % 4] = 2;
			p->p[1 + (i < 4)][i % 4] = 3;
			p->p[0 + 3 * (i < 4)][i % 4] = 4;
		}
		i++;
	}
}

void		ft_presolve_simple_on_row(t_puzzle *p, int clues[16])
{
	int i;

	i = 8;
	while (i < 16)
	{
		if (clues[i] == 1)
			p->p[i % 4][(i > 11) * 3] = 4;
		if (clues[i] == 4)
		{
			p->p[i % 4][3 - 3 * (i < 12)] = 1;
			p->p[i % 4][2 - (i < 12)] = 2;
			p->p[i % 4][1 + (i < 12)] = 3;
			p->p[i % 4][0 + 3 * (i < 12)] = 4;
		}
		i++;
	}
}

void		ft_presolve_pair_on_col(t_puzzle *p, int clues[16])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (clues[i] == 1 && clues[i + 4] == 2)
			p->p[3][i] = 3;
		if (clues[i] == 1 && clues[i + 4] == 3)
			p->p[3][i] = 2;
		if (clues[i] == 2 && clues[i + 4] == 3)
			p->p[1][i] = 4;
		if (clues[i] == 2 && clues[i + 4] == 1)
			p->p[0][i] = 3;
		if (clues[i] == 3 && clues[i + 4] == 1)
			p->p[0][i] = 2;
		if (clues[i] == 3 && clues[i + 4] == 2)
			p->p[2][i] = 4;
		i++;
	}
}

void		ft_presolve_pair_on_row(t_puzzle *p, int clues[16])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (clues[i + 8] == 1 && clues[i + 12] == 2)
			p->p[i][3] = 3;
		if (clues[i + 8] == 1 && clues[i + 12] == 3)
			p->p[i][3] = 2;
		if (clues[i + 8] == 2 && clues[i + 12] == 3)
			p->p[i][1] = 4;
		if (clues[i + 8] == 2 && clues[i + 12] == 1)
			p->p[i][0] = 3;
		if (clues[i + 8] == 3 && clues[i + 12] == 1)
			p->p[i][0] = 2;
		if (clues[i + 8] == 3 && clues[i + 12] == 2)
			p->p[i][2] = 4;
		i++;
	}
}
