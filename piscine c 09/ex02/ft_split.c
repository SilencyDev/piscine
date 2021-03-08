/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 16:15:59 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/26 17:19:55 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		count_word(char *str, char *charset)
{
	int i;

	i = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!is_charset(*str, charset) && *str)
		{
			while (!is_charset(*str, charset) && *str)
				str++;
			i++;
		}
	}
	return (i);
}

void	ft_strcpy(char *start, char *str, char *dest)
{
	int j;

	j = 0;
	while (start < str)
		dest[j++] = *(start++);
	dest[j] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	char	*start;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char*) * (count_word(str, charset) + 1))))
		return (0);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			start = str;
			while (*str && !is_charset(*str, charset))
				str++;
			dest[i] = malloc(str - start + 1);
			ft_strcpy(start, str, dest[i]);
			i++;
		}
		else
			str++;
	}
	dest[i] = 0;
	return (dest);
}
