/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presolve.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 22:13:43 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/18 22:19:23 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESOLVE_H

# define PRESOLVE_H

void	ft_presolve_simple_on_col(t_puzzle *p, int clues[16]);
void	ft_presolve_simple_on_row(t_puzzle *p, int clues[16]);
void	ft_presolve_pair_on_col(t_puzzle *p, int clues[16]);
void	ft_presolve_pair_on_row(t_puzzle *p, int clues[16]);
#endif
