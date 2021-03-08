/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabalet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:33:20 by alabalet          #+#    #+#             */
/*   Updated: 2020/10/18 23:18:38 by alabalet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H

# define CONSTANTS_H
# define N 4

typedef struct		s_puzzle
{
	int				p[N][N];
	int				row;
	int				col;
	int				next_value;
	struct s_puzzle	*previous;
}					t_puzzle;
void				ft_free(t_puzzle *puzzle);
void				ft_print_puzzle(t_puzzle *puzzle);
int					ft_parse_input(char *input, int clues[16]);
t_puzzle			*ft_backtracing(t_puzzle *cur_puzzle, int clues[16]);
t_puzzle			*create_next_puzzle(t_puzzle *cur_puzzle);
void				puzzle_cpy(t_puzzle *dest, t_puzzle *src);
int					is_puzzle_solved(t_puzzle *puzzle);
int					is_row_legal(t_puzzle *p, int row);
int					is_col_legal(t_puzzle *p, int col);
int					is_puzzle_legal(t_puzzle *puzzle, int clues[16]);
int					count_building(int a, int b, int c, int d);
int					is_respecting_clues(t_puzzle *puzzle, int clues[16]);
t_puzzle			*ft_election(int clues[16]);
void				ft_fill_obvious(t_puzzle *p, int clues[16]);
t_puzzle			*ft_init();
int					is_solved_puzzle(t_puzzle *puzzle);
#endif
