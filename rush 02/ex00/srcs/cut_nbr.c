/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:35:47 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:35:48 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_iterative_power(long nb, long power)
{
	long long res;

	res = 1;
	if (power < 0)
		return (0);
	while (power-- != 0)
		res = res * nb;
	return (res);
}

void	print_triplet(char *str, char **dict, int len_dict, int *final)
{
	print_nbr(str[0] - '0', dict, len_dict, final);
	if (str[0] != '0')
		print_nbr(100, dict, len_dict, final);
	if (str[1] == '1' && (str[2] >= '1' && str[2] <= '9'))
		print_nbr(10 + (str[2] - '0'), dict, len_dict, final);
	else
	{
		print_nbr(10 * (str[1] - '0'), dict, len_dict, final);
		print_nbr(str[2] - '0', dict, len_dict, final);
	}
}

char	*exception(int len)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * (len * 11))))
		return (NULL);
	tab[i] = '1';
	while (++i <= len)
		tab[i] = '0';
	tab[i] = '\0';
	return (tab);
}

void	cut_nbr(char *str, char **dict, int len_dict)
{
	long long	len;
	int			*final;
	int			i;

	i = 0;
	final = &i;
	len = ft_strlen(str);
	while (len > 0)
	{
		if (len == 3)
			print_triplet(str, dict, len_dict, final);
		else
			print_triplet(str, dict, len_dict, final);
		len -= 3;
		if (len)
		{
			if (str[0] != '0' || str[1] != '0' || str[2] != '0')
			{
				print_tab(exception(len), dict, len_dict);
			}
			str += 3;
		}
	}
}
