/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:36:18 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:36:19 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		parse_d(int i, int j, int len, char **tab)
{
	while (++j < len)
	{
		i = 0;
		while (tab[j][i] != '\0')
		{
			while (tab[j][i] == ' ')
				i++;
			while (tab[j][i++] >= '0' && tab[j][i] <= '9')
				if (tab[j][i] < '0' && tab[j][i] > '9')
					return (0);
			while (tab[j][i] == ' ')
				i++;
			if (tab[j][i] != ':')
				return (0);
			i++;
			while (tab[j][i] >= 32 && tab[j][i] <= 126)
				i++;
			if (tab[j][i] != '\0')
				return (0);
		}
		if (tab[j][i] != '\0')
			return (0);
	}
	return (1);
}

int		parse_dict(char **tab)
{
	int		i;
	int		j;
	int		len;

	j = -1;
	i = 0;
	len = 0;
	while (tab[i++] != 0)
		len++;
	if (!(parse_d(i, j, len, tab)))
		return (0);
	return (1);
}
