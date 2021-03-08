/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:35:13 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:56:25 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_index_of(char *str, char **strs, int size);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
char	*ft_rev_int_tab(char *str);
char	*ft_itoa(long nbr);
char	**ft_split(char *str, char *charset, int *len);
char	*read_file(char *name);
int		arg_is_valid(int ac, char **av, char **dict, int len);
char	*ft_malloc(char *str, char *charset);
int		ft_str_word(char *str, char *charset);
int		ft_is_charset(char index, char *charset);
void	print_nbr(long nb, char **dict, int len, int *final);
void	print_tab(char *nb, char **dict, int len);
void	print_triplet(char *str, char **dict, int len_dict, int *final);
char	*exception(int len);
void	cut_nbr(char *str, char **dict, int len_dict);
int		ft_iterative_power(long nb, long power);
char	*clean_dic(char *str);
void	put_str(char *str);
int		av_is_valid(char *av, char **dict, int len);
void	format_string(char *temp, char **dict, int len);
int		arg_is_zero(char *av, char **dict, int len);
int		temp_check(char *temp, char **dict, int len);
char	*split_file(char *tab);
int		ft_error(int file);
int		parse_d(int i, int j, int len, char **tab);
int		parse_dict(char **tab);
#endif
