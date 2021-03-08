/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:39:05 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/18 23:13:45 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "constants.h"
#include <unistd.h>

int		ft_parse_input(char *input, int clues[16])
{
	int cpt;
	int figure_is_correct;
	int bool2;

	cpt = 0;
	while (cpt < 16)
	{
		figure_is_correct = ('1' <= input[2 * cpt] && input[2 * cpt] <= '4');
		bool2 = (input[2 * cpt + 1] == '\0' || input[2 * cpt + 1] == ' ');
		if (figure_is_correct && bool2)
			clues[cpt] = input[2 * cpt] - 48;
		else
			return (1);
		cpt++;
	}
	return (0);
}

void	ft_print_puzzle(t_puzzle *puzzle)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = puzzle->p[i][j] + '0';
			write(1, &c, 1);
			if (j < 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_free(t_puzzle *puzzle)
{
	if (puzzle->previous)
		ft_free(puzzle->previous);
	free(puzzle);
}

int		main(int argc, char **argv)
{
	int			clues[16];
	t_puzzle	*bt_puzzle;
	int			error;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	error = ft_parse_input(argv[1], clues);
	if (error)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	bt_puzzle = ft_election(clues);
	bt_puzzle = ft_backtracing(bt_puzzle, clues);
	if (!bt_puzzle)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_print_puzzle(bt_puzzle);
	free(bt_puzzle);
	return (0);
}
