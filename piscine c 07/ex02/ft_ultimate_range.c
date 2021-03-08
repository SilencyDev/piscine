/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:00:45 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/26 18:35:21 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	rmin;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	if (!(range[0] = malloc(sizeof(int) * (max - min))))
		return (-1);
	rmin = min;
	while (max > min)
		range[0][i++] = min++;
	return (max - rmin);
}
