/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_dic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:35:42 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:35:43 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

char	*clean_dic(char *str)
{
	char	*tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = ft_strlen(str);
	if (!(tab = (char *)malloc(sizeof(char) * j + 1)))
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			tab[k] = str[i];
			i++;
			k++;
		}
	}
	tab[k] = '\0';
	return (tab);
}
