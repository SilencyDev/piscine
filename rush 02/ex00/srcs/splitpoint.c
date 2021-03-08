/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitpoint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcarella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:36:32 by pcarella          #+#    #+#             */
/*   Updated: 2020/10/25 19:36:33 by pcarella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_is_charset(char index, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (index == charset[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_str_word(char *str, char *charset)
{
	int word;
	int i;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset) == 0)
			i++;
		if (str[i] && ft_is_charset(str[i], charset) == 1)
		{
			word++;
			while (str[i] && ft_is_charset(str[i], charset) == 1)
				i++;
		}
	}
	return (word);
}

char	*ft_malloc(char *str, char *charset)
{
	char	*tab;
	int		i;

	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 1)
		i++;
	if (!(tab = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && ft_is_charset(str[i], charset) == 1)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char *str, char *charset, int *len)
{
	char	**string;
	int		i;
	int		j;

	i = ft_str_word(str, charset);
	j = 0;
	if (!(string = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[j])
	{
		while (str[j] && ft_is_charset(str[j], charset) == 0)
			j++;
		if (str[j] && ft_is_charset(str[j], charset) == 1)
		{
			string[i] = ft_malloc((str + j), charset);
			i++;
			while (str[j] && ft_is_charset(str[j], charset) == 1)
				j++;
		}
	}
	string[i] = NULL;
	*len = i;
	return (string);
}
