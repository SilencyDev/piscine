/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:35:50 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:35:51 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		arg_is_zero(char *av, char **dict, int len)
{
	int		i;
	int		j;
	int		*final;
	int		k;

	k = 0;
	final = &k;
	i = 0;
	j = 0;
	while (av[i] == ' ' && av[i] != '\0')
		i++;
	while (av[i] == '0' && av[i] != '\0')
	{
		i++;
		j++;
	}
	while (av[i] == ' ' && av[i] != '\0')
		i++;
	if (av[i] == '\0' && j > 0)
	{
		print_nbr(-1, dict, len, final);
		return (1);
	}
	return (0);
}

int		arg_is_valid(int ac, char **av, char **dict, int len)
{
	if (ac == 2)
	{
		if (!arg_is_zero(av[1], dict, len))
			av_is_valid(av[1], dict, len);
		return (1);
	}
	else if (ac == 3)
	{
		if (!arg_is_zero(av[2], dict, len))
			av_is_valid(av[2], dict, len);
		return (1);
	}
	else
	{
		write(1, "Error", 5);
		return (0);
	}
}

int		av_is_valid(char *av, char **dict, int len)
{
	int		i;
	int		j;
	char	temp[50];

	i = 0;
	j = 0;
	while (av[i] == ' ' && av[i] != '\0')
		i++;
	while (av[i] == '0' && av[i] != '\0')
		i++;
	while ((av[i] >= '0' && av[i] <= '9') && j < 42 && av[i] != '\0')
		temp[j++] = av[i++];
	temp[j] = '\0';
	while (av[i] != '\0')
	{
		if (av[i] == ' ')
			i++;
		else
		{
			write(1, "Error", 5);
			return (0);
		}
	}
	return (temp_check(temp, dict, len));
}

int		temp_check(char *temp, char **dict, int len)
{
	if ((temp[0] == '\0') || (ft_strlen(temp) >= 39))
	{
		write(1, "Error", 5);
		return (0);
	}
	format_string(temp, dict, len);
	return (1);
}

void	format_string(char *temp, char **dict, int len)
{
	char	dest[255];
	int		diff;
	int		i;
	int		j;

	diff = 39 - ft_strlen(temp);
	i = 0;
	while (i < diff)
	{
		dest[i] = '0';
		i++;
	}
	j = 0;
	while (temp[j] != '\0')
	{
		dest[i] = temp[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	cut_nbr(dest, dict, len);
}
