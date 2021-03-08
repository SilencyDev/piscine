/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 10:36:38 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/26 18:11:29 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		i;

	if (min >= max)
		return (0);
	if (!(range = malloc(sizeof(int) * (max - min))))
		return (0);
	i = 0;
	while (min < max)
		range[i++] = min++;
	return (range);
}
