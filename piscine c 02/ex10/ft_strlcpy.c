/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <kmacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 20:31:21 by kmacquet          #+#    #+#             */
/*   Updated: 2021/01/19 15:24:13 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	j = i;
	i = 0;
	while (i < size - 1 && i < j)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (j);
}

int	main(void)
{
	char s[4];
	char s1[4];

	printf("%u\n", ft_strlcpy(s, "hello", 5));
	printf("%lu\n", strlcpy(s, "hello", 5));
	return(0);
}
