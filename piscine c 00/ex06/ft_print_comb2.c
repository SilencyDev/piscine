/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmacquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 20:36:31 by kmacquet          #+#    #+#             */
/*   Updated: 2020/10/08 22:39:35 by kmacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_char(char c)
{
	write(1, &c, 1);
}

void	ft_print_number(int a, int b)
{
	ft_print_char('0' + a / 10);
	ft_print_char('0' + a % 10);
	ft_print_char(' ');
	ft_print_char('0' + b / 10);
	ft_print_char('0' + b % 10);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_number(a, b);
			if (a != 98)
			{
				ft_print_char(',');
				ft_print_char(' ');
			}
			++b;
		}
		b = 0;
		++a;
	}
}
