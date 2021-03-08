/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:19:52 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/26 17:15:55 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *dest, char *src)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	while (dest[j])
		j++;
	while (src[i])
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
}

void	ft_strcatthis(char **strs, int size, char *dest, char *sep)
{
	int i;

	i = 0;
	while (strs[i] && i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i < size - 1)
			ft_strcat(dest, sep);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		lenmax;
	int		i;
	char	*dest;

	lenmax = 0;
	i = 0;
	if (size == 0)
		return (malloc(sizeof(char)));
	while (strs[i] && i < size)
		lenmax += ft_strlen(strs[i++]);
	lenmax += ft_strlen(sep) * (size - 1);
	if (!(dest = malloc(lenmax + 1)))
		return (0);
	ft_strcatthis(strs, size, dest, sep);
	return (dest);
}
