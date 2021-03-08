/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:53:26 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/08 20:21:48 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	n;
	int	o;
	int p;

	n = '0' - 1;
	while (++n <= '7')
	{
		o = n;
		while (++o <= '8')
		{
			p = o;
			while (++p <= '9')
			{
				write(1, &n, 1);
				write(1, &o, 1);
				write(1, &p, 1);
				if (n == '7' && o == '8' && p == '9')
					break ;
				ft_put_char(',');
				ft_put_char(' ');
			}
		}
	}
}
