/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:36:07 by pcarella          #+#    #+#             */
/*   Updated: 2021/01/25 14:05:20 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi(char *str)
{
	int		i;
	int		n;
	int		total;

	total = 0;
	n = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		n = (str[i] == '-') ? (-n) : (n);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += str[i] - '0';
		i++;
	}
	return (total * n);
}

char	*ft_rev_int_tab(char *str)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(long nbr)
{
	long	i;
	int		negatif;
	char	*tab;

	i = 0;
	negatif = 0;
	tab = malloc(sizeof(char) * 13);
	if (nbr == 0)
		return ("0");
	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr < 0)
	{
		negatif = 1;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		tab[i] = '0' + (nbr % 10);
		i++;
		nbr /= 10;
	}
	if (negatif == 1)
		tab[i] = '-';
	return (ft_rev_int_tab(tab));
}
