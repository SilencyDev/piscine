/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 10:00:35 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/20 21:32:52 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;

	i = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = nb;
	while (--power > 0)
		i *= nb;
	return (i);
}
